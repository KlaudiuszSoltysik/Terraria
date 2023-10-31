#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

#include "abstract_rectangle_shape.hpp"


class Button : public AbstractRectangleShape {
private:
    sf::Text text;
    sf::Font font;
    sf::RectangleShape button;
    std::function<void()> on_click;
    std::string text_string;
    sf::Vector2f size;
public:
    Button(std::function<void()> on_click=[](){}, std::string text_string="", sf::Vector2f size=sf::Vector2f(0, 0), sf::Vector2f position=sf::Vector2f(0, 0), sf::Color color=sf::Color::Magenta);
    ~Button();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void detectOnClick(sf::RenderWindow &window);
    virtual void setSize(sf::Vector2f size);
    virtual void setPosition(sf::Vector2f position);
};

#endif