#include "shape_container.hpp"


ShapeContainer::ShapeContainer() {
}

ShapeContainer::~ShapeContainer() {
}

void ShapeContainer::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    int elements_count = container.size();
    int margin = 2;
    int margins_combined = 2 * (margin * (elements_count - 1));
    int aviable_space = size.x - margins_combined;
    int position_offset = 0;
    
    for (int i = 0; i < elements_count; i++) {
        container[i]->setSize(sf::Vector2f(aviable_space / elements_count, size.y));
        container[i]->setPosition(sf::Vector2f((i + 1) * position.x + position_offset, position.y));

        position_offset += 2 * margin;

        window.draw(*container[i], states);
    }
}

void ShapeContainer::pushBack(std::shared_ptr<AbstractRectangleShape> shape) {
    container.push_back(shape);
}

void ShapeContainer::setSize(sf::Vector2f size) {
    size = size;
}

void ShapeContainer::setPosition(sf::Vector2f position) {
    size = position;
}