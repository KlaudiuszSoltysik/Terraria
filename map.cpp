#include "map.hpp"


Map::Map() {
    std::ifstream map_file;
    map_file.open(map_filename);

    std::stringstream file_contents;
    file_contents << map_file.rdbuf();

    map_file.close();

    contents = file_contents.str();

    texture_brick1.loadFromFile("assets/textures/brick_1.jpg");
    texture_brick2.loadFromFile("assets/textures/brick_2.png");
}

Map::~Map() {
}

void Map::setBlockWidth(sf::RenderWindow &window) {
    block_width = window.getSize().y / 10;
}

void Map::update(sf::RenderWindow &window) {
    int col = 0;
    int row = 0;

    for (char c : contents) {
        sf::Sprite sprite;

        if (c == '\n') {
            row++;
            col = 0;
            continue;
        } else if (c == '_') {
            sprite.setTexture(texture_brick1);
            sprite.setScale(block_width / texture_brick1.getSize().x, block_width / texture_brick1.getSize().y);
        } else if (c == '#') {
            sprite.setTexture(texture_brick2);
            sprite.setScale(block_width / texture_brick1.getSize().x, block_width / texture_brick1.getSize().y);
        }

        sprite.setPosition(col * block_width, row * block_width);
        
        window.draw(sprite);

        col++;
    }
}