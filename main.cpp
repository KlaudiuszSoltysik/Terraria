#include <SFML/Graphics.hpp>

#include "game.cpp"

/*
g++ *.cpp -o executeable -lsfml-graphics -lsfml-window -lsfml-system
./executeable
*/

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dungeon");
    window.setFramerateLimit(60);

    Game game(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    game.LMBPress();
                }
            }
        }

        
        window.clear();

        game.update();

        window.display();
    }

    return 0;
}