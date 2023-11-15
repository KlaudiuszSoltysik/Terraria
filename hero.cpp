#ifndef HERO_HPP
#define HERO_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <algorithm>
#include <vector>


class Hero : public sf::RectangleShape {
    private:
        sf::RenderWindow &m_window;
        double m_y_velocity = 1.0;
        sf::Vector2f m_position;
        double m_gravity = 0.8;
        int m_block_width;
    public:
        Hero(sf::RenderWindow &window) : m_window(window), m_block_width(window.getSize().y / 10), sf::RectangleShape(sf::Vector2f(window.getSize().y / 10, window.getSize().y / 10)) {
            setPosition(sf::Vector2f(3 * m_block_width, 300));
            setFillColor(sf::Color::Magenta);
        }

        void update(std::vector<sf::RectangleShape> &walls) {
            m_position = getPosition();
            sf::Vector2u window_size = m_window.getSize();
            
            if (m_y_velocity != 0.0) {
                m_y_velocity += m_gravity;
            }
                
            double position_y = m_position.y + m_y_velocity;

            if (position_y < m_block_width) {
                position_y = m_block_width;
                m_y_velocity = 0.0;
            } else if (position_y > window_size.y - 2 * m_block_width - 6) {
                position_y = window_size.y - 2 * m_block_width - 6;
                m_y_velocity = 0.0;
            }

            checkCollision(walls, position_y);

            setPosition(m_position.x, position_y);
        }

        void jump() {
            if (m_y_velocity == 0.0) {
                m_y_velocity = -23.0;
            }
        }

        void checkCollision(std::vector<sf::RectangleShape> &walls, double &position_y) {
            sf::Vector2f hero_position = getPosition();
            sf::Vector2f hero_size = getSize();

            int hero_top = hero_position.y;
            int hero_bottom = hero_position.y + hero_size.y;
            int hero_left = hero_position.x;
            int hero_right = hero_position.x + hero_size.x;

            for (auto &wall : walls) {
                sf::Vector2f wall_position = wall.getPosition();
                sf::Vector2f wall_size = wall.getSize();

                int wall_top = wall_position.y;
                int wall_bottom = wall_position.y + wall_size.y;
                int wall_left = wall_position.x;
                int wall_right = wall_position.x + wall_size.x;

                if (hero_top < wall_bottom && hero_bottom > wall_bottom && (hero_right > wall_left || hero_left < wall_right)) {
                    m_y_velocity = 0.0;
                    position_y = wall_bottom;

                    return;
                } else if (hero_bottom > wall_top && hero_top < wall_top && (hero_right > wall_left || hero_left < wall_right)) {
                    if (m_y_velocity > 0.0) {
                        
                        position_y = wall_top - hero_size.y;
                    }
                    m_y_velocity = 0.0;

                    return;
                }
            }
        }
};

#endif