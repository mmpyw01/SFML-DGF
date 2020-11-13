#ifndef SFML_DGF_BLOOD_H
#define SFML_DGF_BLOOD_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Blood {
private:
    sf::RectangleShape self;
    sf::Image spritesheet;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock animClock;
    float speed;
    void animation();
public:
    explicit Blood(float speed);
    void setPosition(sf::Vector2f vec2f);
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    void update(float dt);
    void draw(sf::RenderWindow& render);
};


#endif //SFML_DGF_BLOOD_H