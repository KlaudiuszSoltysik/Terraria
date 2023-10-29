#ifndef GAME_H
#define GAME_H

#include "map.hpp"
#include "button.hpp"


class Game {
private:
   Map map;
   Button play_button;
   Button menu_button;
   std::string state = "menu";
public:
    Game(sf::RenderWindow &window);
    ~Game();
    void update(sf::RenderWindow &window, bool LMB_pressed);
    void renderMenu(sf::RenderWindow &window);
    void renderInterface(sf::RenderWindow &window);
};

#endif