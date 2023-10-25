#ifndef GAME_H
#define GAME_H

#include "map.hpp"


class Game {
private:
   Map map;
public:
    Game(sf::RenderWindow &window);
    ~Game();
    void update(sf::RenderWindow &window);
};

#endif