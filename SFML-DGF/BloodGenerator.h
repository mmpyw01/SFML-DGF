#ifndef SFML_DGF_BLOODGENERATOR_H
#define SFML_DGF_BLOODGENERATOR_H

#define SPAWN_X 3000
#define SPAWN_Y 250
#define SPAWN_RANDOM_Y 100

#include <SFML/Graphics/RenderWindow.hpp>
#include "Blood.h"
#include "Player.h"

class BloodGenerator {
private:
    std::vector <Blood> self;
    Player& player;
    sf::Clock clock;
    sf::Clock spawnClock;
    void add(sf::Vector2f vec2f);
public:
    explicit BloodGenerator(Player& ref_player);
    void spawn();
    void update(float dt);
    void draw(sf::RenderWindow& render);
    void restart();
    int ulti=0;
};


#endif //SFML_DINO_BLOODGENERATOR_H