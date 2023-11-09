#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <memory>

#include "map.cpp"
#include "button.cpp"
#include "progress_bar.cpp"
#include "shape_container.cpp"


class Interface {
    private:
        sf::Music m_music;
        std::string &m_state;
        double m_volume = 5;
        bool &m_LMB_pressed;
        sf::RenderWindow &m_window;
    public:
        Interface(std::string &state, bool &LMB_pressed, sf::RenderWindow &window) : m_state(state), m_LMB_pressed(LMB_pressed), m_window(window) {
            m_music.openFromFile("assets/sound/magenta.wav");
            m_music.play();
            m_music.setVolume(m_volume * 10);
            m_music.setLoop(true);
        }

        void update() {
            sf::Vector2u window_size = m_window.getSize();

            sf::RectangleShape button_rectangle;
            button_rectangle.setFillColor(sf::Color::Magenta);

            sf::Font font;
            font.loadFromFile("assets/fonts/caveat.ttf");

            if (m_state == "menu") {
                int button_width = window_size.x / 4;
                int button_height = window_size.y / 10;

                sf::Text play_button_text("PLAY", font);

                Button play_button(button_rectangle, play_button_text, [this]() {m_state = "game";}, m_window);
                play_button.setSize(sf::Vector2f(button_width, button_height));
                play_button.setPosition(sf::Vector2f((window_size.x / 2) - (button_width / 2), (window_size.y / 2) - (button_height / 2) - 20 - button_height));

                sf::Text volume_down_button_text("-", font);
                Button volume_down_button(button_rectangle, volume_down_button_text, [this]() {
                    if (m_volume > 0.0) {
                        m_volume--; 
                        m_music.setVolume(m_volume * 10);
                    }
                }, m_window);
                volume_down_button.setSize(sf::Vector2f(button_width / 2, button_height));
                
                ProgressBar volume_bar(m_volume / 10, m_window);
                volume_bar.setSize(sf::Vector2f(button_width, button_height));

                sf::Text volume_up_button_text("+", font);
                Button volume_up_button(button_rectangle, volume_up_button_text, [this]() {
                    if (m_volume < 10.0) {
                        m_volume++; 
                        m_music.setVolume(m_volume * 10);
                    }
                }, m_window);
                volume_up_button.setSize(sf::Vector2f(button_width / 2, button_height));

                ShapeContainer container(m_window);
                container.pushBack(&volume_down_button);
                container.pushBack(&volume_bar);
                container.pushBack(&volume_up_button);

                sf::Vector2f container_size = container.getSize();
                
                container.setPosition(sf::Vector2f((window_size.x / 2) - (container_size.x / 2), (window_size.y / 2) - (container_size.y / 2) + 20));
                
                m_window.draw(play_button);
                m_window.draw(container);

                if (m_LMB_pressed) {
                    play_button.checkOnClick();
                    volume_up_button.checkOnClick();
                    volume_down_button.checkOnClick();
                }
            } else if (m_state == "game") {
                int button_width = window_size.x / 10;
                int button_height = window_size.y / 20;

                sf::Text menu_button_text("MENU", font);

                Button menu_button(button_rectangle, menu_button_text, [this]() {m_state = "menu";} , m_window);
                menu_button.setSize(sf::Vector2f(button_width, button_height));
                menu_button.setPosition(sf::Vector2f(10, 10));

                m_window.draw(menu_button);

                if (m_LMB_pressed) {
                    menu_button.checkOnClick();
                }
            }

            m_LMB_pressed = false;
        }
};

#endif