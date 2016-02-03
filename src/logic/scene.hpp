#pragma once
#include <string>
#include <memory>
#include <map>
#include <list>
#include "creature.hpp"



class Scene {
public:
    Scene(const std::string& title);

    void setDescription(const std::string& description);
    void addCreature(std::unique_ptr<Creature> creature);
    void addObject(std::unique_ptr<Entity> entity);

    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const Creature& getCreature(const std::string& name) const;
    Creature& getCreature(const std::string& name);
    const std::map<std::string, std::unique_ptr<Creature>>& getCreatures() const;
    auto getObjects() const -> const std::list<std::unique_ptr<Entity>>&;

private:
    std::string title;
    std::string description;
    std::map<std::string, std::unique_ptr<Creature>> creatures;
    std::list<std::unique_ptr<Entity>> objects;
};
