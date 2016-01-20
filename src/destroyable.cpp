#include "destroyable.hpp"
#include <random>
#include <functional>


Destroyable::Destroyable(uint16_t maxHP, uint16_t defence):
    maxHP {maxHP},
    defense {defence} {
}



void Destroyable::setDefense(uint16_t defense) {
    this->defense = defense;
}



void Destroyable::damage(uint16_t damage, int16_t attack) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, attack);
    auto roll = std::bind(distribution, generator);
    if(roll() > defense) {
        reduceHP(damage);
    }
}



void Destroyable::restore(uint16_t restored_hp) {
    if(maxHP-restored_hp < currentHP) {
        currentHP += restored_hp;
    } else {
        currentHP = maxHP;
    }
}



void Destroyable::setMaxHP(uint16_t hp) {
    maxHP = hp;
}



uint16_t Destroyable::getCurrentHP() const {
    return currentHP;
}



uint16_t Destroyable::getMaxHP() const {
    return maxHP;
}



bool Destroyable::isDestroyed() const {
    return currentHP > 0;
}



void Destroyable::reduceHP(uint16_t value) {
    if(value >= currentHP) {
        currentHP = 0;
    } else {
        currentHP -= value;
    }
}
