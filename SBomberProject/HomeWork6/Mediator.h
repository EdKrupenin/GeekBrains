//
// Created by Ed Krupenin on 09.02.2022.
//

#ifndef HOMEWORK6_MEDIATOR_H
#define HOMEWORK6_MEDIATOR_H
#include <vector>

class IDivice(){
public:
    virtual void DoSomething(bool checkDay) = 0;
};

class Calendar;

class Mediator {
private:
    Calendar* calendar{};
    std::vector<IDivice*> device{};
    bool checkDay(){
        return calendar->checkCalendar();
    }
public:
    void AddDevice(IDivice* dev){
        device.push_back(dev);
    }
    void Notify(){
        for(const auto& item:device){
            item->BeNotified(checkDay());
        }
    }
};

//Календарь в данном случае может выступать в качестве медиатора так как все действия основаны на нем.
class Calendar{
    Mediator* pMediator{};
public:
    void NewDay(){
        pMediator->Notify();
    }
    bool checkCalendar(){
        return true;  // Упрощенная реализация, должен возвращать true, если рабочий день.
    }
};

class CoffeeMaker : public IDivice{
    void doCoffee(){
        std::cout << "Starting coffee" << std::endl;
    }
public:
    CoffeeMaker()  = default;
    void DoSomething(bool checkDay) override{
        if(checkDay) doCoffee();
    }
};

class TeaPot : public IDivice{
    void doTea(){
        std::cout << "Starting tea" << std::endl;
    }
public:
    TeaPot() = default;
    void DoSomething(bool checkDay) override{
        if(checkDay) doTea();
    }
};

class Alarm : public IDivice{
private:
    void doAlarm(bool checkDay){
        std::cout << "Rise and shine, Mr. Freeman ";
        if(checkDay) std::cout<<"let's go to work";
        else std::cout<<"stay in the bad";
        std::cout<< std::endl;
    }
public:
    Alarm() = default;
    void DoSomething(bool checkDay) override{
        doAlarm(checkDay);
    }
};



#endif //HOMEWORK6_MEDIATOR_H
