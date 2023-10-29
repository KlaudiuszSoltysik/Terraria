#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>


class Button : public sf::Drawable {
private:
    sf::Text text;
    sf::Font font;
    sf::RectangleShape button;
    std::function<void()> on_click;
public:
    Button(sf::Vector2f size=sf::Vector2f(0, 0), sf::Vector2f position=sf::Vector2f(0, 0), std::function<void()> on_click=[](){}, std::string text_string="button", sf::Color color=sf::Color::Magenta);
    ~Button();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void detectOnClick(sf::RenderWindow &window);
};

#endif