#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Audio.hpp>

#include <memory>

#include "game.hpp"
#include "map.hpp"
#include "button.hpp"
#include "progress_bar.hpp"
#include "shape_container.hpp"


class Game {
private:
    Map map;
    sf::Music music;
    std::string state = "menu";
    int volume = 5;
    bool LMB_pressed = false;
public:
    Game(sf::RenderWindow &window);
    ~Game();
    void update(sf::RenderWindow &window);
    void LMBPress();
};

#endif