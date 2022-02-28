//
// Created by krupenin on 24.01.2022.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Pizza{
public:
    virtual void prepare(std::string) = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
    virtual ~Pizza() = default;
};

class CheesePizza:public Pizza{
    void prepare(std::string type) override{
        std::cout<<"cheese"<<std::endl;
    }
    void bake() override{};
    void cut() override{};
    void box() override{};
};
class GreekPizza:public Pizza{
    void prepare(std::string type) override{
        std::cout<<"greek"<<std::endl;
    }
    void bake() override{};
    void cut() override{};
    void box() override{};
};
class PepperoniPizza:public Pizza{
    void prepare(std::string type) override{
        std::cout<<"pepperoni"<<std::endl;
    }
    void bake() override{};
    void cut() override{};
    void box() override{};
};

class PizzaFactory {
public:
   Pizza* createPizza(std::string type){
        if (type == "cheese"){
            return createCheesePizza();
        }
        else if (type == "greek"){
            return createCheesePizza();
        }
        else if (type == "pepperoni"){
            return createCheesePizza();
        }
        return nullptr;
    }
    virtual ~PizzaFactory() = default;
protected:
    Pizza* createCheesePizza() {
        return new CheesePizza;
    }
    Pizza* createGreekPizza() {
        return new GreekPizza;
    }
    Pizza* createPepperoniPizza()  {
        return new PepperoniPizza;
    }
};

Pizza *orderPizza(std::string type) {
    auto* pPizzaFactory = new PizzaFactory;
    auto answer = pPizzaFactory->createPizza(type);
    delete pPizzaFactory;
    return answer;
}
//-----------------------------------------------------------------//

enum class Colors {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    CYAN,
    BLUE,
    VIOLET,
    WHITE
};

class Lightbulb
{
private:
    bool state;
    Colors color;
public:
    Lightbulb(): state(false), color(Colors::WHITE){};

    void On(){
        if(!state){
            state = true;
        }
    };

    void Off(){
        if(state){
            state = false;
        }
    };

    void changeColor(Colors newColor){
        color = newColor;
    }

    Colors getColor() const{
        return this->color;
    }

    bool getState() const {
        return state;
    }
};

class Command // базовый класс «Команда» имеет две виртуальные функции Выполнения и Отмены
{
protected:
    Lightbulb* light;
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
    virtual void unExecute() = 0;

    void setLightbulb(Lightbulb* _light)
    {
        light = _light;
    }
};

class LightCommand : public Command {
public:
    LightCommand() = default;
    void Execute() override {
        light->On();
    }
    void unExecute() override{
        light->Off();
    }
};

class ChangeColor : public Command{
    Colors _color;
    Colors _old_color;
public:
    explicit ChangeColor(Colors color): _color(color) {};
    void Execute() override {
        _old_color = light->getColor();
        light->changeColor(_color);
    }
    void unExecute() override{
        light->changeColor(_old_color);
    }
};

class Invoker{
    std::vector<Command*> DoneCommand;
    Command* pCommand;
    Lightbulb light;
public:
    Invoker() :pCommand(nullptr) {}
    ~Invoker(){
        for (auto ptr: DoneCommand) {
            delete ptr;
        }
    }

    void LightCMD(){
        pCommand = new LightCommand();
        pCommand->setLightbulb(&light);
        pCommand->Execute();
        DoneCommand.push_back(pCommand);
    }

    void ColorCMD(Colors color){
        pCommand = new ChangeColor(color);
        pCommand->setLightbulb(&light);
        pCommand->Execute();
        DoneCommand.push_back(pCommand);
    }

    void newYearCMD(){
        for (auto element: DoneCommand) {
            element->Execute();
        }
        std::for_each(DoneCommand.rbegin(),DoneCommand.rend(),
                      [](auto& element){ return element->Execute(); });
    }

    void Undo(){
        if (DoneCommand.empty())
        {
            std::cout << "There is nothing to undo!" << std::endl;
        }
        else
        {
            pCommand = DoneCommand.back();
            DoneCommand.pop_back();
            pCommand->unExecute();
            delete pCommand;
        }
    }

}

//----------------------------------------------------------------------//

class Beverage{            // Абстрактный класс
public:
    virtual ~Beverage() = default;
    virtual double getDescription() const = 0;
    virtual double cost() const = 0;
};
/**
 * Конкретные Компоненты предоставляют реализации поведения по умолчанию. Может
 * быть несколько вариаций этих классов.
 */
class HouseBlend: public Beverage{   // Молотый
public:
    double cost() const override {
        return 5.5;
    }
};
class DarkRoast: public Beverage{  // Темной обжарки
    double cost() const override {
        return 6.0;
    }
};
class Decaf: public Beverage{    // Без кофеина
    double cost() const override {
        return 7.3;
    }
};
class Espresso: public Beverage{  // Эспрессо
    double cost() const override {
        return 3.5;
    }
};
/**
 * Базовый класс Декоратора следует тому же интерфейсу, что и другие компоненты.
 * Основная цель этого класса - определить интерфейс обёртки для всех конкретных
 * декораторов. Реализация кода обёртки по умолчанию может включать в себя поле
 * для хранения завёрнутого компонента и средства его инициализации.
 */
class Decorator : public Beverage{
protected:
    Beverage* beverage_;
public:
    explicit Decorator(Beverage* beverage) : beverage_(beverage) {}
    /**
    * Декоратор делегирует всю работу обёрнутому компоненту.
    **/
    double cost() const override {
            return this->beverage_->cost();
    }
};
//шоколад
class Chocolate : public Decorator{
public:
    explicit Chocolate(Beverage* beverage): Decorator(beverage){}
    double cost() const override {
        return 1.2+Decorator::cost();
    }
};
//корица
class Cinnamon : public Decorator{
public:
    explicit Cinnamon(Beverage* beverage): Decorator(beverage){}
    double cost() const override {
        return 1 + Decorator::cost();
    }
};
//взбитые сливки
class WhippedСream : public Decorator{
public:
    explicit WhippedСream(Beverage* beverage): Decorator(beverage){}
    double cost() const override {
        return 2.2+Decorator::cost();
    }
};

class Sugarless : public Decorator{
public:
    explicit Sugarless(Beverage* beverage): Decorator(beverage){}
    double cost() const override {
        return Decorator::cost() - 0.5;
    }
};

/**
* Клиентский код работает со всеми объектами, используя интерфейс Компонента.
* Таким образом, он остаётся независимым от конкретных классов компонентов, с
* которыми работает.
*/
void ClientCode(Beverage* beverage) {
    // ...
    std::cout << "RESULT: " << beverage->cost();
    // ...
}



