#include "entity.hpp"



void Entity::setType(const std::string& type) {
    this->type = type;
}



void Entity::setDescription(const std::string& description) {
    this->description = description;
}



void Entity::setPosition(const Point& pos) {
    position = pos;
}



const std::string& Entity::getType() const {
    return type;
}



const std::string& Entity::getDescription() const {
    return description;
}



const Point& Entity::getPosition() const {
    return position;
}
