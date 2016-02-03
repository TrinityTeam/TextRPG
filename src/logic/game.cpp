#include "game.hpp"
#include <iostream>
#include <algorithm>
#include "command_parser.hpp"
#include "scene_reader.hpp"



Game::~Game() {
    std::cout << "Game over\n";
}



void Game::start() {
    player.setName("Me");
    player.setDescription("Really me.");
    player.setMaxHP(3);
    player.restore(3);
    player.setDamage(333);
    player.setAttack(13);
    player.setType("PC");
    player.setDefense(3);

    std::cout << "Game started\n";

    currentScene = SceneReader::readData("../data/scenes/introduction.json");

    while(true) {
        commandParser.readCommand();
        switch(commandParser.getCommandType()) {
        case CommandType::Exit:
            return;

        case CommandType::Look:
            lookCommand();
            break;

        case CommandType::Status:
            statusCommand();
            break;

        case CommandType::Attack:
            attackCommand();
            break;

        default:
            std::cout << "Invalid argument" << std::endl;
        }
    }
}



void Game::lookCommand() const {
    if(commandParser.getArgumentsNum() == 1) {
        std::cout << currentScene->getDescription() << std::endl;
        std::cout << "Creatures: \n";
        for(const auto& pair: currentScene->getCreatures()) {
            Creature* creature = pair.second.get();
            std::cout << creature->getName() << ": "
                      << creature->getType() << std::endl;
        }
        std::cout << "Entities: \n";
        for(auto& entity: currentScene->getObjects()) {
            std::cout << entity->getType() << std::endl;
        }

    } else {
        auto name = commandParser.getString(1);
        try {
            std::cout << currentScene->getCreature(name).getDescription() << std::endl;

        } catch(std::out_of_range) {
            auto& entities = currentScene->getObjects();
            auto entity = std::find_if(std::begin(entities),
                                       std::end(entities),
                                       [&name](const std::unique_ptr<Entity>& e) {
                                           return e->getType() == name;
                                       });
            if(entity != std::end(entities)) {
                std::cout << (*entity)->getDescription() << std::endl;
            } else {
                std::cout << "There is no " << name
                          << " here" << std::endl;
            }
        }
    }
}



void Game::statusCommand() const {
    if(commandParser.getArgumentsNum() == 1) {
        std::cout << "HP: " << player.getCurrentHP()
                  << "/" << player.getMaxHP() << std::endl;

    } else {
        auto name = commandParser.getString(1);

        const auto creature = getCreature(name);
        if(creature != nullptr) {
            std::cout << "HP: " << creature->getCurrentHP()
                      << "/" << creature->getMaxHP() << std::endl;
        }
    }
}



void Game::attackCommand() {
    try {
        auto name = commandParser.getString(1);

        auto creature = getCreature(name);
        if(creature != nullptr) {
            player.assault(*creature);
        }

    } catch(std::out_of_range) {
        std::cout << "You must specify target\n";
    }
}



Creature* Game::getCreature(const std::string& name) {
    try {
        auto creature = &currentScene->getCreature(name);
        return creature;

    } catch (std::out_of_range) {
        std::cout << "There is no " << name
                  << " here" << std::endl;
        return nullptr;
    }
}



const Creature* Game::getCreature(const std::string& name) const {
    try {
        auto creature = &currentScene->getCreature(name);
        return creature;

    } catch (std::out_of_range) {
        std::cout << "There is no " << name
                  << " here" << std::endl;
        return nullptr;
    }
}
