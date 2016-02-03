#pragma once
#include <string>
class Creature;



class Skill {
public:
    virtual ~Skill();

    void setName(const std::string& name);
    const std::string& getName() const;

    void setDescription(const std::string& description);
    const std::string& getDescription() const;

    virtual void cast(Creature& caster, Creature& target) = 0;

private:
    std::string name;
    std::string description;

};
