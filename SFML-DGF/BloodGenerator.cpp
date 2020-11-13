#include "BloodGenerator.h"
#include <math.h>

BloodGenerator::BloodGenerator(Player& ref_player) : player(ref_player) {
}

void BloodGenerator::add(sf::Vector2f vec2f) {
    float multiplier = clock.getElapsedTime().asSeconds();
    Blood blood(500 + multiplier * 10);
    blood.setPosition(vec2f);
    self.push_back(blood);
}

void BloodGenerator::spawn() {
    float time = spawnClock.getElapsedTime().asSeconds();
    float multiplier = clock.getElapsedTime().asSeconds();
    if (time > 10 - (multiplier * 0.0001)) {
        spawnClock.restart();
        add(sf::Vector2f(SPAWN_X, SPAWN_Y + rand() % SPAWN_RANDOM_Y));
    }
}

void BloodGenerator::update(float dt) {
    if (player.isGameOver()) {
        return;
    }

    spawn();

    for (auto it = self.begin(); it != self.end();) {
        it->update(dt);
        if (it->getGlobalBounds().intersects(player.getGlobalBounds())) {
            it = self.erase(it);
            ulti++;
            printf("%d\n", ulti);
            if (ulti == 3) {
                printf("Ulti is already");
                player.ulti();
            }
        }     
        else {
            ++it;
        }
    }
}

void BloodGenerator::draw(sf::RenderWindow& render) {
    for (auto& it : self) {
        it.draw(render);
    }
}

void BloodGenerator::restart() {
    clock.restart();
    spawnClock.restart();
    ulti = 0;
    self = std::vector<Blood>();
}