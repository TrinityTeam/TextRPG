#include "game.hpp"
#include <iostream>



Game::~Game() {
    std::cout << "Game over\n";
}



void Game::start() {
    std::cout << "Game started\n";
}
