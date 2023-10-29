#include <SFML/Graphics.hpp>

#include "game.hpp"

/*
g++ *.cpp -o executeable -lsfml-graphics -lsfml-window -lsfml-system
./executeable
*/

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dungeon");
    window.setFramerateLimit(60);

    Game game(window);

    while (window.isOpen()) {
        bool LMB_pressed = false;

        // Detect events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    LMB_pressed = true;
                }
            }
        }

        
        window.clear();

        game.update(window, LMB_pressed);

        window.display();
    }

    return 0;
}