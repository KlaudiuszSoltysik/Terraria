#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "hero.cpp"


class Map {
    private:
        sf::RenderWindow &m_window;
        float m_block_width;
        std::string m_contents;
        std::string m_map_filename = "map.txt";
        Hero m_hero;
        std::map<char, std::vector<sf::RectangleShape>> m_map;
        double m_x_speed = 2;
    public:
        Map(sf::RenderWindow &window) : m_window(window), m_block_width(window.getSize().y / 10), m_hero(window) {
            std::ifstream map_file;
            map_file.open(m_map_filename);

            std::stringstream file_contents;
            file_contents << map_file.rdbuf();

            map_file.close();

            m_contents = file_contents.str();

            int col = 0;
            int row = 0;

            for (char c : m_contents) {
                sf::RectangleShape rec;
                rec.setSize(sf::Vector2f(m_block_width, m_block_width));
                sf::Vector2f position(col * m_block_width, row * m_block_width);
            
                if (c == '\n') {
                    row++;
                    col = 0;
                    continue;
                } else if (c == '_') {
                    rec.setFillColor(sf::Color::Black);
                    rec.setPosition(position);
                    m_map['_'].push_back(rec);
                } else if (c == '#') {
                    rec.setFillColor(sf::Color::Cyan);
                    rec.setPosition(position);
                    m_map['#'].push_back(rec);
                } else if (c == '*') {
                    rec.setFillColor(sf::Color::Yellow);
                    rec.setPosition(position);
                    m_map['*'].push_back(rec);
                }
                
                m_window.draw(rec);

                col++;
            }
        }

        void update() {
            m_x_speed += 0.005;

            for (auto &pair : m_map) {
                for (sf::RectangleShape &rec : pair.second) {
                    sf::Vector2f position = rec.getPosition();

                    rec.setPosition(position.x - m_x_speed, position.y);
                    m_window.draw(rec);
                }
            }

            m_hero.update(m_map['*']);
            m_window.draw(m_hero);
        }

        void heroJump() {
            m_hero.jump();
        }
};

#endif