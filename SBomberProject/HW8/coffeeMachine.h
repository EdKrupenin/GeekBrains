//
// Created by edkru on 16.02.2022.
//
#pragma once
#include <string>

class StateContext;

class CoffeeMachine;

class State{
private:
    CoffeeMachine& owner{};
    std::string name{};
public:
    explicit State(const std::string &name) : name(name), owner(CoffeeMachine::GetInstance()) {}
    const std::string &getState() const {
        return name;
    }
    virtual void TossTheCoin(StateContext*) = 0:
    virtual void BuyButton(StateContext*) = 0;
    virtual void ReturnTheCoin(StateContext*) = 0;
    //Служебный метод проверям только после покупки мб стоит спрятать в приватную секцию
    virtual void CheckCoffee(StateContext*) = 0;
};

class StateContext{
private:
    State* state;
public:
    explicit StateContext(State *state) : state(state) {}

    void TossACoin(){
        std::cout << "Toss the coin " << state->getName() << "..." << std::endl;
        state->TossTheCoin(this);
    }
    void BuyButton(){
        std::cout << "Press Buy Button " << state->getName() << "..." << std::endl;
        state->BuyButton(this);
    }
    void ReturnTheCoin(){
        std::cout << "Return The Coin " << state->getName() << "..." << std::endl;
        state->ReturnTheCoin(this);
    }
    void CheckCoffee(){
        std::cout << "Checking Coffee " << state->getName() << "..." << std::endl;
        state->CheckCoffee(this);
    }

    State* GetState(){
        return state;
    }

    void setState(State *newState) {
        std::cout << "Chaging newState from " << state->getName()
                  << " to " << newState->getName() << "..." << std::endl;
        delete state;
        state = newState;
    }

    virtual ~StateContext() {
        delete state;
    }
};

class HaveNotTheCoin : public State{
public:
    explicit HaveNotTheCoin() : State("Have Not The Coin") {}
    void TossTheCoin(StateContext* state) override;
    void BuyButton(StateContext* context) override;
    void ReturnTheCoin(StateContext* context) override;
    void CheckCoffee(StateContext* context) override;
};

class HaveTheCoin: public State{
public:
    explicit HaveTheCoin() : State("Have the coin") {}
    void TossTheCoin(StateContext* context) override;
    void BuyButton(StateContext* state) override;
    void ReturnTheCoin(StateContext* context) override;
    void CheckCoffee(StateContext* context) override;

};

class SoldCoffee : public State{
public:
    explicit SoldCoffee() : State("Buy Coffee") {}
    void TossTheCoin(StateContext* context) override;
    void BuyButton(StateContext* context) override;
    void ReturnTheCoin(StateContext* context) override;
    void CheckCoffee(StateContext* context) override;
};

class HaveNotTheCoffee : public State{
public:
    explicit HaveNotTheCoffee(const std::string &name) : State("Haven't the coffee") {}
    void TossTheCoin(StateContext* context) override;
    void BuyButton(StateContext* context) override;
    void ReturnTheCoin(StateContext* context) override;
    void CheckCoffee(StateContext* context) override;
};

void HaveNotTheCoin::TossTheCoin(StateContext *state) {
    owner->setCoin(true);
    state->setState(new HaveTheCoin);
}

void HaveNotTheCoin::BuyButton(StateContext *context) {
    std::cout<<"Error operation"<<std::endl;
}

void HaveNotTheCoin::ReturnTheCoin(StateContext *context) {
    std::cout<<"Error operation"<<std::endl;
}

void HaveNotTheCoin::CheckCoffee(StateContext *context) {
    std::cout<<"Error operation"<<std::endl;
}

void HaveTheCoin::TossTheCoin(StateContext *context) {
    owner->setCoin(true);
}

void HaveTheCoin::BuyButton(StateContext *state) {
    if(owner->getCoin() > 0)
        owner->setCoin(false);
        state->setState(new SoldCoffee);
    else{
        std::cout<<"Haven't coin!"<<std::endl;
        state->setState(new HaveNotTheCoin);
    }
}

void HaveTheCoin::ReturnTheCoin(StateContext *context) {
    if(owner->getCoin() > 1)
        owner->setCoin(false);// по хорошему перегрузить операторы ++ и -- у кофейного аппарата
    else{
        owner->setCoin(false);
        state->setState(new HaveNotTheCoin);
    }
}

void HaveTheCoin::CheckCoffee(StateContext *context) {
    std::cout<<"Error operation"<<std::endl;
}

void SoldCoffee::TossTheCoin(StateContext *context) {
    std::cout<<"Error operation"<<std::endl;
}

void SoldCoffee::BuyButton(StateContext *context) {
    std::cout<<"Error operation"<<std::endl;
}

void SoldCoffee::ReturnTheCoin(StateContext *context) {
    std::cout<<"Error operation"<<std::endl;
}

void SoldCoffee::CheckCoffee(StateContext *context) {
    if(owner->getCoffee > 0){
        owner->setCoffe(false);
        if(owner->getCoin() > 0)
            context->setState(new HaveTheCoin);
        else
            context->setState(new HaveNotTheCoin);
    }
    else
        context->setState(new HaveNotTheCoffee);
}

class CoffeeMachine{
private:
    CoffeeMachine() = default;
    int _coin{};
    int _coffee{};
    StateContext* _pState = new StateContext(new HaveTheCoin());
    static CoffeeMachine* _uniqueInstance;
public:
    virtual ~CoffeeMachine();
    CoffeeMachine(CoffeeMachine& other) = delete;
    void operator=(CoffeeMachine&) = delete;
    static CoffeeMachine* GetInstance();

    int getCoin() const{
        return _coin;
    }
    int getCoffee() const {
        return _coffee;
    }

    StateContext *getState() const {
        return _pState;
    }

    void setCoin(bool inc) {
        if(inc)
            _coin++;
        else
            _coin--;
    }

    void setCoffee(bool inc) {
        if(inc) _coffee++;
        else    _coffee--;
    }
};

CoffeeMachine* CoffeeMachine::_uniqueInstance = nullptr;

CoffeeMachine* CoffeeMachine::GetInstance() {
    m1.lock();
    if (_uniqueInstance == nullptr){
        _uniqueInstance = new CoffeeMachine();
    }
    m1.unlock();
        return _uniqueInstance;
}

CoffeeMachine::~CoffeeMachine() {
        delete _uniqueInstance;
}

void coffee(){
    auto cMachine = CoffeeMachine::GetInstance();
    auto machineState = cMachine->getState();
    if(machineState != nullptr){
        machineState->TossACoin();
        machineState->TossACoin();
        machineState->TossACoin();
        machineState->BuyButton();
        machineState->ReturnTheCoin();

    }
}