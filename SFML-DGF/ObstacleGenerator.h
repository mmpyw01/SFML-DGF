#ifndef SFML_DGF_OBSTACLEGENERATOR_H
#define SFML_DGF_OBSTACLEGENERATOR_H

#define SPAWN_X 3000
#define SPAWN_Y 342
#define SPAWN_RANDOM_Y 1

#include <SFML/Graphics/RenderWindow.hpp>
#include "Obstacle.h"
#include "Player.h"

class ObstacleGenerator {
private:
    std::vector <Obstacle> self;
    Player& player;
    sf::Clock clock;
    sf::Clock spawnClock;
    void add(sf::Vector2f vec2f);
public:
    explicit ObstacleGenerator(Player& ref_player);
    void spawn();
    void update(float dt);
    void draw(sf::RenderWindow& render);
    void restart();
};


#endif //SFML_DGF_OBSTACLEGENERATOR_H