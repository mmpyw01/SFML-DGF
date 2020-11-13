#ifndef SFML_DINO_GENERATOR_H
#define SFML_DINO_OBSTACLEGENERATOR_H

#define SPAWN_X 3000
#define SPAWN_Y 342
#define SPAWN_RANDOM_Y 1

#include <SFML/Graphics/RenderWindow.hpp>
#include "Background.h"
#include "Player.h"

class BackgroundGenerator {
private:
    std::vector <Background> self;
    Player& player;
    sf::Clock clock;
    sf::Clock spawnClock;
    void add(sf::Vector2f vec2f);
public:
    explicit BackgroundGenerator(Player& ref_player);
    void spawn();
    void update(float dt);
    void draw(sf::RenderWindow& render);
    void restart();
};


#endif //SFML_DINO_OBSTACLEGENERATOR_H