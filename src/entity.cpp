#include "entity.hpp"



void Entity::setType(const std::string& type) {
    this->type = type;
}



void Entity::setDescription(const std::string& description) {
    this->description = description;
}



const std::string& Entity::getType() const {
    return type;
}



const std::string& Entity::getDescription() const {
    return description;
}
