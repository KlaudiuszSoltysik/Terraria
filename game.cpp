#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "map.hpp"


Game::Game(sf::RenderWindow &window) {
    this->map.setBlockWidth(window);
}

Game::~Game() {
}

void Game::update(sf::RenderWindow &window) {
    this->map.update(window);
}
