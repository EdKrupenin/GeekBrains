//
// Created by edkru on 16.02.2022.
//
#pragma once

class Prototype {
private:
    int hp;
    int atk;
    int def;
    std::string type{};
public:
    explicit Prototype(int hp, int atk, int def, const std::string &type) : hp(hp), atk(atk), def(def), type(type) {}
    int getHp() const {
        return hp;
    }

    int getAtk() const {
        return atk;
    }

    int getDef() const {
        return def;
    }

    Prototype(const Prototype& other, int level){
        hp = other.hp * level;
        atk = other.atk * level;
        def = other.def * level;
        type = other.type;
    }

    Prototype *clone(int level) const {
        return new Prototype(*this,level);
    }

    void changeHp(int change){
        hp += change;
    }
    void changeAtk(int change){
        atk += change;
    }
    void changeDef(int change){
        def += change;
    }
};

class Monster : Prototype{
public:
    Monster(Prototype& parent, int level) : Prototype(parent.clone(level)) {}
};

#endif //HW8_PROTOTYPE_H
