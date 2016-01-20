#pragma once
#include "data_reader.hpp"
#include "entity.hpp"



class EntityReader: public DataReader<Entity> {
public:
    static std::unique_ptr<Entity> readData(const std::string &filepath) {
        Json::Value root = parseFile(filepath);

        auto entity = std::make_unique<Entity>();
        entity->setType(root["type"].asString());
        entity->setDescription(root["description"].asString());

        return entity;
    }

private:


};
