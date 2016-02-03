#include "creature.hpp"
#include <random>
#include <functional>
#include <iostream>



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
    std::random_device rand;
    auto attack_roll = rand()%attack+attack/2;
    auto damage_roll = rand()%damage+damage/2;
    std::cout << "Attack roll: " << attack_roll
              << "\nDamage roll: " << damage_roll << "\n";
    target.damage(damage_roll, attack_roll);
}
