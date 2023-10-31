#ifndef ABSTRACTRECTANGLESHAPE_HPP
#define ABSTRACTRECTANGLESHAPE_HPP

#include <SFML/Graphics.hpp>


class AbstractRectangleShape : public sf::RectangleShape {
private:
    
public:
    AbstractRectangleShape();
    ~AbstractRectangleShape();
    virtual void setSize(sf::Vector2f size);
    virtual void setPosition(sf::Vector2f position);
};

#endif