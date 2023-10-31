#include "game.hpp"

Game::Game(sf::RenderWindow &window) {
    map.setBlockWidth(window);
    music.openFromFile("assets/sound/magenta.wav");
    music.play();
    music.setVolume(volume * 10);
    music.setLoop(true);
}

Game::~Game() {
}

void Game::update(sf::RenderWindow &window) {
    sf::Vector2u window_size = window.getSize();

    if (state == "menu") {
        int button_width = window_size.x / 4;
        int button_height = window_size.y / 10;

        Button play_button([this]() {state = "game";}, "PLAY", sf::Vector2f(button_width, button_height), sf::Vector2f((window_size.x / 2) - (button_width / 2), (window_size.y / 2) - (button_height / 2) - 20));

        ShapeContainer container;

        container.pushBack(std::make_shared<Button>([this]() {volume--;}, "-"));
        // container.pushBack(std::make_shared<ProgressBar>(volume / 10));
        // container.pushBack(std::make_shared<Button>([this]() {volume++;}, "+"));
        
        container.setSize(sf::Vector2f(button_width, button_height));
        container.setPosition(sf::Vector2f((window_size.x / 2) - (button_width / 2), (window_size.y / 2) - (button_height / 2) + 20));
        
        window.draw(play_button);
        window.draw(container);

        if (LMB_pressed) {
            play_button.detectOnClick(window);
        }
    } else if (state == "game") {
        int button_width = window_size.x / 10;
        int button_height = window_size.y / 20;

        Button menu_button([this]() {state = "menu";}, "MENU", sf::Vector2f(button_width, button_height), sf::Vector2f(10, 10));

        map.update(window);
        window.draw(menu_button);

        if (LMB_pressed) {
            menu_button.detectOnClick(window);
        }
    }

    LMB_pressed = false;
}

void Game::LMBPress() {
    LMB_pressed = true;
}