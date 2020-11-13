#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ObstacleGenerator.h"
#include "BloodGenerator.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Dino",sf::Style::Titlebar|sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    sf::Event event{};
    sf::Clock dtClock;
    sf::Clock clock;

    
    Player player;
    BloodGenerator bloodGenerator(player);
    ObstacleGenerator obstacleGenerator(player);
    
    sf::Texture t;
    if (!t.loadFromFile("asset/bg2.png"))
        return EXIT_FAILURE;
    t.setRepeated(true);
    sf::Sprite background(t);
    background.setPosition(0, 0);
    background.setColor(sf::Color(255, 255, 255, 200));

    sf::Shader parallaxShader;
    parallaxShader.loadFromMemory(
        "uniform float offset;"

        "void main() {"
        "    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
        "    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
        "    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;" // magic
        "    gl_FrontColor = gl_Color;"
        "}"
        , sf::Shader::Vertex);

    float offset = 0.f;
    sf::Clock clock3;

    while (window.isOpen()) {
        sf::Time dtTime = dtClock.restart();

        float dt = dtTime.asSeconds();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        if (player.isGameOver() && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            player.restart();
            bloodGenerator.restart();
            obstacleGenerator.restart();
        }
        
        parallaxShader.setUniform("offset", offset += clock3.restart().asSeconds() / 20);
        
        bloodGenerator.update(dt);
        obstacleGenerator.update(dt);
        player.update(window, dt);

        window.clear();
        window.draw(background, &parallaxShader);
        obstacleGenerator.draw(window);
        bloodGenerator.draw(window);
        player.draw(window);

        window.display();
    }

    return 0;
}