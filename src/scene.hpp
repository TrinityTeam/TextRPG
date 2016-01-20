#pragma once
#include <string>
#include <memory>
#include <list>
#include "creature.hpp"



class Scene {
public:
    Scene(const std::string& title);

    void setDescription(const std::string& description);
    void addCreature(std::unique_ptr<Creature> creature);

    const std::string& getTitle() const;
    const std::string& getDescription() const;

private:
    std::string title;
    std::string description;
    std::list<std::unique_ptr<Creature>> creatures;
    std::list<std::unique_ptr<Entity>> objects;
};
