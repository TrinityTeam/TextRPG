#include "scene.hpp"



Scene::Scene(const std::string& title):
    title {title} {

}



void Scene::setDescription(const std::string& description) {
    this->description = description;
}



void Scene::addCreature(std::unique_ptr<Creature> creature) {
    creatures.push_back(std::move(creature));
}



const std::string& Scene::getTitle() const {
    return title;
}



const std::string& Scene::getDescription() const {
    return description;
}
