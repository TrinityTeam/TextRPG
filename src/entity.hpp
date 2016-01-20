#pragma once
#include <string>




class Entity {
public:
    Entity() = default;
    virtual ~Entity() = default;

    void setType(const std::string& type);
    void setDescription(const std::string& description);

    const std::string& getType() const;
    const std::string& getDescription() const;

private:
    std::string type;
    std::string description;
};
