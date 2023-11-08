#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


class Map {
    private:
        sf::RenderWindow &m_window;
        float m_block_width;
        std::string m_contents;
        std::string m_map_filename = "map.txt";
        sf::Texture m_texture_brick1;
        sf::Texture m_texture_brick2;
    public:
        Map(sf::RenderWindow &window) : m_window(window), m_block_width(window.getSize().y / 10) {
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
                sf::Sprite sprite;

                if (c == '\n') {
                    row++;
                    col = 0;
                    continue;
                } else if (c == '_') {
                    sf::Vector2u size = m_texture_brick1.getSize();

                    sprite.setTexture(m_texture_brick1);
                    sprite.setScale(m_block_width / size.x, m_block_width / size.y);
                } else if (c == '#') {
                    sf::Vector2u size = m_texture_brick2.getSize();

                    sprite.setTexture(m_texture_brick2);
                    sprite.setScale(m_block_width / size.x, m_block_width / size.y);
                }

                sprite.setPosition(col * m_block_width, row * m_block_width);
                
                m_window.draw(sprite);

                col++;
            }
        }
};

#endif