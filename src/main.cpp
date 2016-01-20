#include "game.hpp"
#include "creature.hpp"


class A {};
class B: public A {};

int main() {
    Game game;
    game.start();

    Creature c1, c2;

    return 0;
}
