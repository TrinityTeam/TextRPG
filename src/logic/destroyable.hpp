#pragma once
#include <cinttypes>



class Destroyable {
public:
    Destroyable(uint16_t maxHP = {}, uint16_t defense = {});

    void setDefense(uint16_t defense);
    void damage(uint16_t damage, int16_t attack = 0);
    void restore(uint16_t restored_hp);
    void setMaxHP(uint16_t hp);

    uint16_t getCurrentHP() const;
    uint16_t getMaxHP() const;
    bool isDestroyed() const;

private:
    void reduceHP(uint16_t value);

    uint16_t maxHP {};
    uint16_t currentHP {};
    uint16_t defense {};

};
