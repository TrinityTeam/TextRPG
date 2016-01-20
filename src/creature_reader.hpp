#pragma once
#include "entity_reader.hpp"
#include "creature.hpp"



class CreatureReader: public DataReader<Creature> {
public:
    CreatureReader();

    static std::unique_ptr<Creature> readData(const std::string& filepath) {
        Json::Value root = parseFile(filepath);

        std::unique_ptr<Creature> creature(std::make_unique<Creature>(*EntityReader::readData(filepath).release()));

        creature->setMaxHP(root["hp"].asUInt());
        creature->setAttack(root["attack"].asUInt());
        creature->setDefense(root["defense"].asUInt());
        creature->setDamage(root["damage"].asUInt());

        return std::move(creature);
    }

private:


};
