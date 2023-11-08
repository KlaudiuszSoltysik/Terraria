#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Audio.hpp>

#include <memory>

#include "map.cpp"
#include "interface.cpp"


class Game {
    private:
        Map m_map;
        sf::Music m_music;
        std::string m_state = "menu";
        double m_volume = 5;
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
};

#endif