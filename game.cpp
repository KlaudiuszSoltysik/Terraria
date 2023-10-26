#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "map.hpp"
#include "button.hpp"


Game::Game(sf::RenderWindow &window) {
    map.setBlockWidth(window);
}

Game::~Game() {
}

void Game::update(sf::RenderWindow &window) {
    if (state == "menu") {
        renderMenu(window);
    } else {
        map.update(window);
    }
}

void Game::renderMenu(sf::RenderWindow &window) {
    sf::Vector2u window_size = window.getSize();
    int button_width = window_size.x / 4;
    int button_height = window_size.y / 10;

    Button play_button(sf::Vector2f(button_width, button_height), sf::Vector2f((window_size.x / 2) - (button_width / 2), (window_size.y / 2) - (button_height / 2)), "PLAY");
    window.draw(play_button);
}
