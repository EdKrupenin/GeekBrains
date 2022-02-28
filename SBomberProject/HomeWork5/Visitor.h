//
// Created by edkru on 04.02.2022.
//

#ifndef HOMEWORK5_VISITOR_H
#define HOMEWORK5_VISITOR_H

#include <string>

class Visitor {
public:
    virtual void VisitMenuItem(const MenuItem *element) const = 0;
    virtual void VisitIngredient(const Ingredient *element) const = 0;
};


class Menu{
public:
    virtual ~Menu() {}
    virtual void Accept(Visitor *visitor) const = 0;
}


class MenuItem: public Menu{
private:
    std::string name;
    std::string description;
    float price;
    std::vector<Ingredient*> ingredients;
public:
    MenuItem(const std::string &name, const std::string &description, float price) : name(name),
                                                                                     description(description),
                                                                                     price(price) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getDescription() const {
        return description;
    }

    float getPrice() const {
        return price;
    }

    void Accept(Visitor *visitor) override{
        visitor->VisitMenuItem(this);
    }
};

class Ingredient: public MenuItem{
private:
    std::string name;
    int healthRating;
    float Calories;
    float Protein;
    float Carbs;
    float Fats;
public:
    const std::string &getName1() const {
        return name;
    }

    int getHealthRating() const {
        return healthRating;
    }

    float getCalories() const {
        return Calories;
    }

    float getProtein() const {
        return Protein;
    }

    float getCarbs() const {
        return Carbs;
    }

    float getFats() const {
        return Fats;
    }

    void Accept(Visitor *visitor){
        visitor->VisitIngredient(this);
    }
}

class ConcreteVisitor : public Visitor{
public:
    void VisitMenuItem(const MenuItem *element) const override{
        element->getDescription();
        element->getName();
        element->getName();
    }
    void VisitIngredient(const Ingredient *element) const override{
        element->getCalories();
        element->getCarbs();
        element->getFats();
        element->getHealthRating()
        element->getProtein();
    }
};






#endif //HOMEWORK5_VISITOR_H
