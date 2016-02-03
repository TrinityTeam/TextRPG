#pragma once
#include <map>
#include "skill.hpp"
#include "entity.hpp"
#include "destroyable.hpp"



class Creature: public Entity, public Destroyable {
public:
    Creature() = default;

    void setName(const std::string& name);
    const std::string& getName() const;

    void setAttack(uint16_t attack);
    void setDamage(uint16_t damage);

    void assault(Destroyable& target);

private:
    std::string name;

    uint16_t attack {};
    uint16_t damage {};

    std::map<std::string, Skill*> skills;
};
