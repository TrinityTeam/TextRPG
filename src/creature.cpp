#include "creature.hpp"
#include <random>
#include <functional>



void Creature::setName(const std::string& name) {
    this->name = name;
}



const std::string& Creature::getName() const {
    return name;
}



void Creature::setAttack(uint16_t attack) {
    this->attack = attack;
}



void Creature::setDamage(uint16_t damage) {
    this->damage = damage;
}



void Creature::assault(Destroyable& target) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(damage/2, damage*1.5);
    auto roll = std::bind(distribution, generator);

    target.damage(roll(), attack);
}
