#pragma once
#include <string>
#include "../point.hpp"




class Entity {
public:
    Entity() = default;
    virtual ~Entity() = default;

    void setType(const std::string& type);
    void setDescription(const std::string& description);
    void setPosition(const Point& pos);

    const std::string& getType() const;
    const std::string& getDescription() const;
    const Point& getPosition() const;

private:
    Point position;
    std::string type;
    std::string description;
};
