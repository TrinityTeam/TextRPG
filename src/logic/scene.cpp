#include "scene.hpp"



Scene::Scene(const std::string& title):
    title {title} {
}



void Scene::setDescription(const std::string& description) {
    this->description = description;
}



void Scene::addCreature(std::unique_ptr<Creature> creature) {
    creatures.emplace(std::make_pair(creature->getName(), std::move(creature)));
}



void Scene::addObject(std::unique_ptr<Entity> entity) {
    objects.push_back(std::move(entity));
}



const std::string& Scene::getTitle() const {
    return title;
}



const std::string& Scene::getDescription() const {
    return description;
}



const Creature& Scene::getCreature(const std::string& name) const {
    return *creatures.at(name);
}



Creature& Scene::getCreature(const std::string& name) {
    return *creatures.at(name);
}



const std::map<std::string, std::unique_ptr<Creature>>& Scene::getCreatures() const {
    return creatures;
}



auto Scene::getObjects() const ->
const std::list<std::unique_ptr<Entity>>& {
    return objects;
}
