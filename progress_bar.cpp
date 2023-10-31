// #include "progress_bar.hpp"


// ProgressBar::ProgressBar(double progress, sf::Vector2f size, sf::Vector2f position, sf::Color color) : progress(progress) {
//     full_size = sf::Vector2f(size.x * progress, size.y);
//     empty_size = sf::Vector2f(size.x * (1 - progress), size.y);

//     thickness = size.x / 100;
    
//     full = sf::RectangleShape(full_size);
//     empty = sf::RectangleShape(empty_size);

//     full.setPosition(position);
//     empty.setPosition(sf::Vector2f(position.x + full_size.x - thickness, position.y));

//     full.setFillColor(color);
//     empty.setFillColor(sf::Color::White);

//     empty.setOutlineColor(color);
//     empty.setOutlineThickness(thickness);
// }

// ProgressBar::~ProgressBar() {
// }

// void ProgressBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//     window.draw(full, states);
//     window.draw(empty, states);
// }

// void ProgressBar::setSize(sf::Vector2f size) {
//     full_size = sf::Vector2f(size.x * progress, size.y);
//     empty_size = sf::Vector2f(size.x * (1 - progress), size.y);

//     thickness = size.x / 100;
    
//     full.setSize(full_size);
//     empty.setSize(empty_size);

//     empty.setOutlineThickness(thickness);
// }

// void ProgressBar::setPosition(sf::Vector2f position) {
//     full.setPosition(position);
//     empty.setPosition(sf::Vector2f(position.x + full_size.x - thickness, position.y));
// }