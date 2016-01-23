#include "game.hpp"
#include <iostream>
#include "command_parser.hpp"
#include "scene_reader.hpp"



Game::~Game() {
    std::cout << "Game over\n";
}



void Game::start() {
    std::cout << "Game started\n";

    auto scene = SceneReader::readData("../data/scenes/introduction.json");

    CommandParser commandParser;
    while(true) {
        commandParser.readCommand();
        switch(commandParser.getCommandType()) {
        case CommandType::Exit:
            return;

        case CommandType::Look:
            if(commandParser.getArgumentsNum() == 1) {
                std::cout << scene->getDescription() << std::endl;
            } else {
                try {
                    std::cout << scene->getCreature(commandParser.getString(1)).getDescription() << std::endl;
                } catch(std::out_of_range) {
                    std::cout << "There is no " << commandParser.getString(1) << " here" << std::endl;
                }
            }
            break;

        default:
            std::cout << "Invalid argument" << std::endl;
        }
    }
}
