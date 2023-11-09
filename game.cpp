#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <memory>

#include "map.cpp"
#include "interface.cpp"


class Game {
    private:
        Map m_map;
        std::string m_state = "menu";
        bool m_LMB_pressed = false;
        sf::RenderWindow &m_window;
        Interface interface;
    public:
        Game(sf::RenderWindow &window) : m_window(window), m_map(window), interface(m_state, m_LMB_pressed, m_window) {}

        void LMBPress() {
            m_LMB_pressed = true;
        }

        void update() {
            if (m_state == "game") {
                m_map.update();
            }

            interface.update();
        }

        void spacePress() {
            m_map.heroJump();
        }
};

#endif