#ifndef SFML_DGF_PLAYER_H
#define SFML_DGF_PLAYER_H

#define HEIGHT_STAND 66
#define HEIGHT_CROUCHING 50

#define JUMP_POWER 2000
#define FALL_SPEED 10000
#define START_POSITION_X 100
#define START_POSITION_Y 350

#define SPRITE_WIDTH 100  
#define SPRITE_HEIGHT 100
#define SPRITE_WALK_START 0
#define SPRITE_WALK_END 5
#define SPRITE_DEAD 20
#define SPRITE_CROUNCH 13
#define SPRITE_JUMP 7
#define SPRITE_ULTI_START 22
#define SPRITE_ULTI_END 27

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class Player {
private:
    sf::RectangleShape self;
    sf::Image spritesheet;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    sf::Clock scoreClock;
    sf::Clock animClock;
    sf::Font font;
    sf::Text scoreText;
    sf::Text gameOverText;
    bool isJumping;
    bool isCrouching;
    bool isUlti;
    bool isAlive;
    float ySpeed;
    int score;
    void jump(float dt);
    void crouch(float dt);
    void ulti(float dt);
    void normalise();
    void animation();
public:
    Player();
    sf::FloatRect getGlobalBounds();
    void kill();
    bool isGameOver();
    void update(sf::RenderTarget& render, float dt);
    void draw(sf::RenderWindow& window);
    void restart();
};


#endif //SFML_TUTORIAL_PLAYER_H