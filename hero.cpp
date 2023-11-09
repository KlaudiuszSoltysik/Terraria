#ifndef HERO_HPP
#define HERO_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <algorithm>

class Hero : public sf::RectangleShape {
    private:
        sf::RenderWindow &m_window;
        double m_y_velocity;
        sf::Vector2f m_position;
        double m_gravity = 0.8;
        int m_block_width;
    public:
        Hero(sf::RenderWindow &window) : m_window(window), m_block_width(window.getSize().y / 10), sf::RectangleShape(sf::Vector2f(window.getSize().y / 10, window.getSize().y / 10)) {
            setPosition(sf::Vector2f(3 * m_block_width, 300));
            setFillColor(sf::Color::Magenta);
        }

        void update() {
            m_position = getPosition();
            sf::Vector2u window_size = m_window.getSize();

            m_y_velocity += m_gravity;
                
            double position_y = m_position.y + m_y_velocity;

            if (position_y < m_block_width) {
                position_y = m_block_width;
                m_y_velocity = 0.0;
            } else if (position_y > window_size.y - 2 * m_block_width - 6) {
                position_y = window_size.y - 2 * m_block_width - 6;
                m_y_velocity = 0.0;
            }

            setPosition(m_position.x, position_y);
        }

        void jump() {
            m_y_velocity = -23.0;
        }
};

#endif