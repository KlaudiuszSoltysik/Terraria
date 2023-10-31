#include "abstract_rectangle_shape.hpp"

AbstractRectangleShape::AbstractRectangleShape() {
}

AbstractRectangleShape::~AbstractRectangleShape() {
}

void AbstractRectangleShape::setSize(sf::Vector2f size) {
    sf::RectangleShape::setSize(size);
}

void AbstractRectangleShape::setPosition(sf::Vector2f position) {
    sf::RectangleShape::setPosition(position);
}