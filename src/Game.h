//
// Created by Alex on 02.01.2024.
//

#ifndef SHAPEINVADER_GAME_H
#define SHAPEINVADER_GAME_H


#include "InputManager.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

class Game {
private:
    sf::RenderWindow window;
    sf::Event event{};
    std::vector<std::unique_ptr<Entity>> entities;
    sf::Clock clock;
    sf::Clock asteroidClock;
    sf::Font font;
    sf::Text text;
    enum GameState {
        gameMenueScreen, gamePlay, gameOverScreen
    };
    GameState gameState = GameState::gameMenueScreen;
    float deltaTime{};

    void checkCloseButton();

    void quitGame();

    void updateMenueScreen();

    void updateGameOverScreen();

    void drawGamePlay();

    void drawMenueScreen();

    void drawGameOverScreen();

    void generateAsteroid();

    void clearOffscreenEntities();

    void setText(const std::string& text);

public:
    static const int width = 800;
    static const int height = 600;

    bool isRunning = true;

    Game();

    void update();

    void draw();

    void updateGamePlay();

    void shootBullet();

    sf::Vector2f getShootPosition();

    void removeCollidedEntities();
};


#endif //SHAPEINVADER_GAME_H
