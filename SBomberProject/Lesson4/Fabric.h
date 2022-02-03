//
// Created by edkru on 31.01.2022.
//

#ifndef LESSON4_FABRIC_H
#define LESSON4_FABRIC_H


class Pizza{
public:
    virtual void prepare(std::string);
    virtual void bake() {};
    virtual void cut() {};
    virtual void box() {};
};

class CheesePizza:public Pizza{};
class GreekPizza:public Pizza{};
class PepperoniPizza:public Pizza{};

///Прородительская фабрика
class PizzaFactory
{
public:
    virtual Pizza* createPizza() = 0;
    virtual ~PizzaFactory() = default;
};

///фабрика конкретной пиццы
class CheesePizzaFactory : public PizzaFactory
{
public:
    Pizza* createPizza() override{
        return new CheesePizza();
    };
};

class GreekPizzaFactory : public PizzaFactory
{
public:
    Pizza* createPizza() override{
        return new GreekPizza();
    };
};

class PepperoniPizzaFactory : public PizzaFactory
{
public:
    Pizza* createPizza() override{
        return new PepperoniPizza();
    };
};

///Метод принимает фабрику и работает засчет полиморфизма
Pizza* orderPizza(PizzaFactory* pFactory){
    Pizza* pizza = nullptr;
    pizza = pFactory->createPizza();
    return pizza;
}


#endif //LESSON4_FABRIC_H
