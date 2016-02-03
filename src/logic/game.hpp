#pragma once
#include "scene.hpp"
#include "command_parser.hpp"



class Game {
public:
    Game() = default;
    ~Game();

    void start();

private:
    void lookCommand() const;
    void statusCommand() const;
    void attackCommand();

    Creature* getCreature(const std::string& name);
    const Creature* getCreature(const std::string& name) const;

    std::unique_ptr<Scene> currentScene;
    Creature player;
    CommandParser commandParser;

};
