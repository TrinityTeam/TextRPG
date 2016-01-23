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



const std::string& Scene::getTitle() const {
    return title;
}



const std::string& Scene::getDescription() const {
    return description;
}



const Creature& Scene::getCreature(const std::string& name) const {
    return *creatures.at(name);
}
