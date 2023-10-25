#include <SFML/Graphics.hpp>

#include "game.hpp"

/*
g++ *.cpp -o zGame -lsfml-graphics -lsfml-window -lsfml-system
./zGame
*/

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dungeon");
    window.setFramerateLimit(60);

    Game game(window);

    while (window.isOpen()) {
        // Detect events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        
        window.clear();

        game.update(window);

        window.display();
    }

    return 0;
}