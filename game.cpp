#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "map.hpp"
#include "button.hpp"


Game::Game(sf::RenderWindow &window) {
    map.setBlockWidth(window);

    sf::Vector2u window_size = window.getSize();
    int button_width = window_size.x / 4;
    int button_height = window_size.y / 10;

    play_button = Button(sf::Vector2f(button_width, button_height), sf::Vector2f((window_size.x / 2) - (button_width / 2), (window_size.y / 2) - (button_height / 2)), [this]() {state = "game";}, "PLAY");
    menu_button = Button(sf::Vector2f(window_size.x / 10, window_size.y / 20), sf::Vector2f(10, 10), [this]() {state = "menu";}, "MENU");
}

Game::~Game() {
}

void Game::update(sf::RenderWindow &window, bool LMB_pressed) {
    if (state == "menu") {
        if (LMB_pressed) {
            play_button.detectOnClick(window);
        }

        renderMenu(window);
    } else if (state == "game") {
        if (LMB_pressed) {
            menu_button.detectOnClick(window);
        }

        map.update(window);
        renderInterface(window);
    }
}

void Game::renderMenu(sf::RenderWindow &window) {
    window.draw(play_button);
}

void Game::renderInterface(sf::RenderWindow &window) {
    window.draw(menu_button);
}