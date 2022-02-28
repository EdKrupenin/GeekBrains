//
// Created by edkru on 16.02.2022.
///
#include "memento.h"
#include <utility>

class Player::Impl{
public:
    float hp;
    int speed;
    std::string name;
    Impl(float hp, int speed, std::string name) : hp(hp), speed(speed), name(std::move(name)) { }

};



Player::Player(float hp, int speed, const std::string &name) : pImpl(new Impl(hp, speed, name)){};
void Player::changeSpeed(int change) {
    pImpl->speed += change;
}

void Player::changeHp(float change) {
    pImpl->hp += change;
}

float Player::getHp() const {
    return pImpl->hp;
}

int Player::getSpeed() const {
    return pImpl->speed;
}

const std::string &Player::getName() const {
    return pImpl->name;
}

Memento Player::createMemento() {
    Memento m(pImpl->hp, pImpl->speed, pImpl->name);
    return m;
}

void Player::reinstateMemento(Memento& mem){
    auto memento = mem.getValue();
    pImpl->hp = memento.hp;
    pImpl->speed = memento.speed;
    pImpl->name = std::move(memento.name);
}