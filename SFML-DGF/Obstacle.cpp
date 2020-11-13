#include <SFML/Graphics/RenderWindow.hpp>
#include "Obstacle.h"

Obstacle::Obstacle(float speed) {
    this->speed = speed;
    self = sf::RectangleShape(sf::Vector2f(75, 75));
    self.setOrigin(25, 50);
    self.setFillColor(sf::Color::Red);

    spritesheet.loadFromFile("asset/en1.png");
}

void Obstacle::animation() {
    int frame = animClock.getElapsedTime().asMilliseconds() / 100;
    if (frame > 1) {
        animClock.restart();
        frame = 0;
    }
    texture.loadFromImage(spritesheet, sf::IntRect(frame * 5, 5, 75, 150));
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(1,1));
    sprite.setOrigin(8, 16);
}

void Obstacle::setPosition(sf::Vector2f vec2f) {
    self.setPosition(vec2f);
}

sf::Vector2f Obstacle::getPosition() {
    return self.getPosition();
}

sf::FloatRect Obstacle::getGlobalBounds() {
    return self.getGlobalBounds();
}

void Obstacle::draw(sf::RenderWindow& render) {
    sprite.setPosition(self.getPosition());
    render.draw(sprite);
}

void Obstacle::update(float dt) {
    self.move(-this->speed * dt, 0);
    animation();
}