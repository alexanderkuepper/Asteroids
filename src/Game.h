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

class Game {
private:
    sf::RenderWindow window;
    sf::Event event{};
    Player player{{200, 200}};
    std::vector<std::unique_ptr<Asteroid>> asteroids;
    sf::Clock clock;
    sf::Clock asteroidClock;
    enum GameState {
        gameMenueScreen, gamePlay, gameOverScreen
    };
    GameState gameState = GameState::gamePlay;
    float deltaTime{};

    void checkCloseButton();

    void quitGame();

    void updateMenueScreen();

    void updateGameOverScreen();

    void draw();

    void drawGamePlay();

    void drawMenueScreen();

    void drawGameOverScreen();

    void generateAsteroid();

    void removeAsteroid();

public:
    static const int width = 800;
    static const int height = 600;

    bool isRunning = true;

    Game();

    void update();

    void updateGamePlay();
};


#endif //SHAPEINVADER_GAME_H
