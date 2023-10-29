#include <SFML/Graphics.hpp>
#include <iostream>

#include "button.hpp"


Button::Button(sf::Vector2f size, sf::Vector2f position, std::function<void()> on_click, std::string text_string, sf::Color color) : on_click(on_click) {
    button = sf::RectangleShape(size);
    button.setPosition(position);
    button.setFillColor(color);
    
    font.loadFromFile("assets/fonts/caveat.ttf");
    text.setFont(font);
    text.setString(text_string);
    text.setCharacterSize(size.y * 0.8);
    text.setFillColor(sf::Color::White);
    text.setPosition(position.x + (size.x - text.getGlobalBounds().width) / 2, position.y);
}

Button::~Button() {
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(button, states);
    window.draw(text, states);
}

void Button::detectOnClick(sf::RenderWindow &window) {
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    sf::Vector2f button_position = button.getPosition();
    sf::Vector2f button_size = button.getSize();
    
    if (mouse_position.x >= button_position.x && mouse_position.x <= button_position.x + button_size.x && mouse_position.y >= button_position.y && mouse_position.y <= button_position.y + button_size.y) {
        on_click();
    }
}