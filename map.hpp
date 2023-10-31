#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


class Map {
private:
    float block_width;
    std::string contents;
    std::string map_filename = "map.txt";
    sf::Texture texture_brick1;
    sf::Texture texture_brick2;
public:
    Map();
    ~Map();
    void setBlockWidth(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
};

#endif