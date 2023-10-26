#ifndef GAME_H
#define GAME_H

#include "map.hpp"


class Game {
private:
   Map map;
   std::string state = "menu";
public:
    Game(sf::RenderWindow &window);
    ~Game();
    void update(sf::RenderWindow &window);
    void renderMenu(sf::RenderWindow &window);
};

#endif