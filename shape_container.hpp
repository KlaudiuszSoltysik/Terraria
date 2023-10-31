#ifndef SHAPECONTAINER_HPP
#define SHAPECONTAINER_HPP

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

#include "abstract_rectangle_shape.hpp"


class ShapeContainer : public sf::RectangleShape {
private:
    std::vector<std::shared_ptr<AbstractRectangleShape>> container;
    sf::Vector2f size;
    sf::Vector2f position;
public:
    ShapeContainer();
    ~ShapeContainer();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void pushBack(std::shared_ptr<AbstractRectangleShape> shape);
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
};

#endif