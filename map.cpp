#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "hero.cpp"


class Map {
    private:
        sf::RenderWindow &m_window;
        float m_block_width;
        std::string m_contents;
        std::string m_map_filename = "map.txt";
        sf::Texture m_texture_brick1;
        sf::Texture m_texture_brick2;
        Hero m_hero;
    public:
        Map(sf::RenderWindow &window) : m_window(window), m_block_width(window.getSize().y / 10), m_hero(window) {
            std::ifstream map_file;
            map_file.open(m_map_filename);

            std::stringstream file_contents;
            file_contents << map_file.rdbuf();

            map_file.close();

            m_contents = file_contents.str();

            m_texture_brick1.loadFromFile("assets/textures/brick_1.jpg");
            m_texture_brick2.loadFromFile("assets/textures/brick_2.png");
        }

        void update() {
            int col = 0;
            int row = 0;

            for (char c : m_contents) {
                sf::RectangleShape rec;
                rec.setSize(sf::Vector2f(m_block_width, m_block_width));

                if (c == '\n') {
                    row++;
                    col = 0;
                    continue;
                } else if (c == '_') {
                    rec.setFillColor(sf::Color::Black);
                } else if (c == '#') {
                    rec.setFillColor(sf::Color::Cyan);
                }

                rec.setPosition(col * m_block_width, row * m_block_width);
                
                m_window.draw(rec);

                col++;
            }
            m_hero.update();
            m_window.draw(m_hero);
        }

        void heroJump() {
            m_hero.jump();
        }
};

#endif