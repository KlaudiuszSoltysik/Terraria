#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>


class Button : public sf::Drawable {
private:
   std::string text;
   sf::RectangleShape button;
public:
    Button(sf::Vector2f size=sf::Vector2f(0, 0), sf::Vector2f position=sf::Vector2f(0, 0), std::string text="button", sf::Color color=sf::Color::Magenta);
    ~Button();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};

#endif