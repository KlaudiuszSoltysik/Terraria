#ifndef MAP_H
#define MAP_H


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