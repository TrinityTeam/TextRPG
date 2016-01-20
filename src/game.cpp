#include "game.hpp"
#include <iostream>
#include "scene_reader.hpp"



Game::~Game() {
    std::cout << "Game over\n";
}



void Game::start() {
    std::cout << "Game started\n";

    auto scene = SceneReader::readData("../data/scenes/introduction.json");

}
