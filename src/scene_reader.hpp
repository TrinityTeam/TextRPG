#pragma once
#include "data_reader.hpp"
#include "scene.hpp"
#include "creature_reader.hpp"


#include <iostream>
class SceneReader: public DataReader<Scene> {
public:
    static std::unique_ptr<Scene> readData(const std::string& filepath) {
        Json::Value root = parseFile(filepath);
        auto scene = std::make_unique<Scene>(root["title"].asString());
        scene->setDescription(root["description"].asString());
        for(auto& creature_data: root["creatures"]) {
            auto creature = CreatureReader::readData("../data/entities/creatures/"+
                                                     creature_data["type"].asString()+".json");
            //creature->setName(creature_data["name"].asString());
            scene->addCreature(std::move(creature));
        }
        return scene;
    }

private:

};
