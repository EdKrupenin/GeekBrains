//
// Created by edkru on 09.02.2022.
//

#ifndef HOMEWORK6_COMPOSITE_H
#define HOMEWORK6_COMPOSITE_H
#include <utility>
#include <vector>
#include <string>

class IDish{
public:
    virtual float getPrice() = 0;
    virtual std::string getName() =0;
    virtual ~IDish() = default;
};

class Dish : IDish{
public:
    virtual Dish(std::string name, float price) : name(std::move(name)), price(price) {};
    float getPrice() override {
        return price;
    }
    std::string getName() override {
        return name;
    }
    ~Dish() override = default;
protected:
    std::string name{};
    float price{};
};

class Pancake : public Dish{
public:
    Pancake(const std::string &name, float price) : Dish(name,price) {};
};

class Icecream : public Dish{
public:
    Icecream(const std::string &name, float price) :  Dish(name,price) {};
};

class Beverage : public Dish{
public:
    Beverage(const std::string &name, float price) :  Dish(name,price) {};
};

class MorningPancake : public Pancake{
public:
    explicit MorningPancake: Pancake("Morning pancake", 240.0f) = default;
};

class LunchPancake : public Pancake{
public:
    explicit LunchPancake: Pancake("Lunch pancake", 280.0f) = default;
};

class MexicanPancake : public Pancake{
public:
    explicit MexicanPancake: Pancake("Mexican pancake", 270.0f) = default;;
};

class PotatoPancake : public Pancake{
public:
    explicit PotatoPancake: Pancake("Potato pancake", 210.0f) = default;;
};

class MushroomPancake : public Pancake{
public:
    explicit MushroomPancake: Pancake("Mushroom pancake", 220.0f) = default;;
};

class FalafelPancake : public Pancake{
public:
    explicit FalafelPancake: Pancake("Falafel pancake", 270.0f) = default;;
};

class ChocolatePancake : public Pancake{
public:
    explicit ChocolatePancake: Pancake("Chocolate pancake", 260.0f) = default;;
};

class BananaPancake : public Pancake{
public:
    explicit BananaPancake: Pancake("Banana pancake", 260.0f) = default;;
};

class JamPancake : public Pancake{
public:
    explicit JamPancake: Pancake("Jam pancake", 190.0f) = default;;
};

class BananaSplit : public Icecream{
    explicit BananaSplit : Icecream("Banana Split", 260) = default;
};

class BerryScream : public Icecream{
    explicit BerryScream : Icecream("Berry ice cream", 260) = default;
};

class HotBrauni : public Icecream{
    explicit HotBrauni : Icecream("Hot Brauni", 310)) = default;
};

class TtuttiFruity : public Icecream{
    explicit TuttiFruity : Icecream("Tutti Fruity", 240) = default;
};

class Vanilla : public Icecream{
    explicit Vanilla : Icecream("Vanilla ice cream", 180) = default;
};

class Pistachio : public Icecream{
    explicit Pistachio : Icecream("Pistachio ice cream", 230) = default;
};

class Pepsi : public Beverage {
     explicit Pepsi : Beverage("Pepsi", 120) = default;
};

class Coffee : public Beverage {
    explicit Coffee :Beverage("Coffee", 80) = default;
};

class Tea : public Beverage {
    explicit Tea :Beverage("Tea", 50) = default;
};

class CompositeLunch : IDish {
    std::vector<IDish*> dish{};
public:
     float getPrice() override{
        float price{};
        for (const auto &item: dish) {
            price+= item->getPrice();
        }
        return price;
    }
     std::string getName() override{
         std::string dish_list{};
         for (const auto &item: dish) {
             dish_list.append(item->getName());
             dish_list.append(" ");
         }
        return name;
    }
    void addDish(IDish* input){
         dish.push_back(input);
    }
    ~CompositeLunch() override{
        for (auto& item: dish) {
            delete item;
        }
    }
};

CompositeLunch* breakfast(){
    auto br = new CompositeLunch();
    br->addDish(new MorningPancake);
    br->addDish(new Vanilla);
    br->addDish(new Coffee);
    return br;
}

CompositeLunch* dinner(){
    auto dn = new CompositeLunch();
    dn->addDish(new LunchPancake);
    dn->addDish(new JamPancake);
    dn->addDish(new BerryScream);
    dn->addDish(new Tea);
    return br;
}

CompositeLunch* fastFood(){
    auto br = new CompositeLunch();
    br->addDish(new Pistachio);
    br->addDish(new JamPancake);
    br->addDish(new Pepsi);
    return br;
}

CompositeLunch* complexDay(){
auto cd = new CompositeLunch();
    cd->addDish(breakfast());
    cd-addDish(dinner());
    cd-addDish(fastFood());
}

#endif //HOMEWORK6_COMPOSITE_H
