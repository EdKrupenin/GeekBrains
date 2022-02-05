//
// Created by edkru on 31.01.2022.
//

#ifndef LESSON4_BUILDER_H
#define LESSON4_BUILDER_H

class Events{
public:
    virtual void getEvent() = 0;
    virtual ~Events() = default;;
};

class Hotel: public Events{
public:
    void getEvent() override {
        std::cout << "Booking Hotel" << std::endl;
    }
};

class Park: public Events{
    void getEvent() override {
        std::cout << "Park visiting" << std::endl;
    }
};

class Food: public Events{
public:
    virtual void getEvent() override = 0;
    virtual  ~Food() override = default;
};

class Dinner: public Food{
public:
    explicit Dinner(const std::string &type) : _type("breakfast") {}
    void getEvent() override{
        std::cout << "Food " << _type << std::endl;
    } ;
private:
    std::string _type{};
};

class Lunch: public Food{
public:
    Lunch() : _type("lunch") = default;
    void getEvent() override{
        std::cout << "Food " << _type << std::endl;
    } ;
private:
    std::string _type{};
};

class Breakfast: public Food{
public:
    Breakfast() : _type("breakfast") = default;
    void getEvent() override{
        std::cout << "Food " << _type << std::endl;
    } ;
private:
    std::string _type{};
};

class Special: public Events{
public:
    virtual void info() = 0;
    ~Special() override = default;
};

class Skating:public Special{
public:
    explicit Skating(const std::string &type) : _type("skating") {}
    void info() override{
        std::cout << _type << std::endl;
    } ;
private:
    std::string _type{};
};

class Circus:public Special{
public:
    explicit Circus(const std::string &type) : _type("circus") {}
    void info() override{
        std::cout << _type << std::endl;
    } ;
private:
    std::string _type{};
};

struct Day // Класс "День", содержащий все типы развлечений
{
    vector<Events> events{};
    void info() const {
        for (const auto& i : events)  i.getEvent();
    }
};

class DayBuilder {
protected:
    Day* day{};
public:
    virtual ~DayBuilder() = default;
    virtual void createDay() {} = 0;
    virtual void createHotel() {} = 0;
    virtual void createPark() {} = 0;
    virtual void createDinner() {} = 0;
    virtual void createLunch() {} = 0;
    virtual void createBreakfast() {} = 0;
    virtual void createSkating() {} = 0;
    virtual void createCircus() {} = 0;
    virtual Day *getDay() const {return day;}
}

class DayOne : public DayBuilder{
public:
    void createDay() override {
        day = new Day;
    }

    void createHotel() override {
        day->events.push_back(new Hotel());
    }

    void createPark() override {
        day->events.push_back(new Park());
    }

    void createDinner() override {
        day->events.push_back(new Dinner());
    }
};

class DayTwo : public DayBuilder{
public:
    void createDay() override {
        day = new Day;
    }

    void createHotel() override {
        day->events.push_back(new Hotel());
    }

    void createPark() override {
        day->events.push_back(new Park());
    }

    void createBreakfast() override {
        day->events.push_back(new Breakfast());
    }
    void createDinner() override {
        day->events.push_back(new Dinner());
    }

    void createSkating() override {
        day->events.push_back(new Skating());
    }
};

class DayThree : public DayBuilder{
public:
    void createDay() override {
        day = new Day;
    }

    void createPark() override {
        day->events.push_back(new Park());
    }

    void createBreakfast() override {
        day->events.push_back(new Breakfast());
    }

    void createLunch() override {
       day->events.puch_back(new Lunch());
    }

    void createCircus() override {
        day->events.puch_back(new Circus());
    }

};

class Director{
public:
    Day* createDay(DayBuilder& builder){
        builder.createDay();
        builder.createHotel();
        builder.createPark();
        builder.createDinner();
        builder.createLunch();
        builder.createBreakfast();
        builder.createSkating();
        builder.createCircus();
        return builder.getDay();
    }
};


#endif //LESSON4_BUILDER_H
