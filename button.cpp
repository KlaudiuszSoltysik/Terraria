#include <SFML/Graphics.hpp>

#include "button.hpp"


Button::Button(sf::Vector2f size, sf::Vector2f position, std::string text, sf::Color color) : text(text) {
    button = sf::RectangleShape(size);
    button.setPosition(position);
    button.setFillColor(color);
}

Button::~Button() {
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(button, states);
}