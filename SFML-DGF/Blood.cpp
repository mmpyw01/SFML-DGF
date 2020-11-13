#include <SFML/Graphics/RenderWindow.hpp>
#include "Blood.h"

Blood::Blood(float speed) {
    this->speed = speed;
    self = sf::RectangleShape(sf::Vector2f(100, 100));
    self.setOrigin(25, 50);
    self.setFillColor(sf::Color::Red);

    spritesheet.loadFromFile("asset/blood.png");
}

void Blood::animation() {
    int frame = animClock.getElapsedTime().asMilliseconds() / 300;
    if (frame > 1) {
        animClock.restart();
        frame = 0;
    }
    texture.loadFromImage(spritesheet, sf::IntRect(frame * 5, 5, 100, 100));
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.5, 0.5));
    sprite.setOrigin(8, 16);
}

void Blood::setPosition(sf::Vector2f vec2f) {
    self.setPosition(vec2f);
}

sf::Vector2f Blood::getPosition() {
    return self.getPosition();
}

sf::FloatRect Blood::getGlobalBounds() {
    return self.getGlobalBounds();
}

void Blood::draw(sf::RenderWindow& render) {
    sprite.setPosition(self.getPosition());
    render.draw(sprite);
}

void Blood::update(float dt) {
    self.move(-this->speed * dt, 0);
    animation();
}