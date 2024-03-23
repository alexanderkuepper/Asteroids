//
// Created by Alex on 02.01.2024.
//

#include <memory>
#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode{width, height}, "Shape Invader");
    window.setFramerateLimit(100);
}

void Game::update() {
    deltaTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    switch (gameState) {
        case GameState::gameMenueScreen:
            updateMenueScreen();
            break;
        case GameState::gamePlay:
            updateGamePlay();
            break;
        case GameState::gameOverScreen:
            updateGameOverScreen();
            break;
    }
    checkCloseButton();
}

void Game::draw() {
    window.clear();
    switch (gameState) {
        case GameState::gameMenueScreen:
            drawMenueScreen();
            break;
        case GameState::gamePlay:
            drawGamePlay();
            break;
        case GameState::gameOverScreen:
            drawGameOverScreen();
            break;
    }

    window.display();
}

void Game::checkCloseButton() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            quitGame();
        }
    }
}

void Game::generateAsteroid() {
    if (asteroidClock.getElapsedTime().asSeconds() > 1) {
        asteroids.push_back(std::make_unique<Asteroid>());
        asteroidClock.restart();
    }
}

void Game::removeAsteroid() {
    asteroids.erase(
            std::remove_if(asteroids.begin(), asteroids.end(), [](auto &a) {
                return a->position.y > height;
            }), asteroids.end()
    );
}

void Game::quitGame() {
    window.close();
    isRunning = false;
}

void Game::updateGamePlay() {
    player.update(deltaTime);
    generateAsteroid();
    removeAsteroid();
    for (auto &asteroid: asteroids) {
        asteroid->update(deltaTime);
        if (player.collisionCheck(*asteroid)) {
            gameState = GameState::gameOverScreen;
        }
    }
}

void Game::updateMenueScreen() {

}

void Game::updateGameOverScreen() {

}

void Game::drawGamePlay() {
    player.draw(window);
    for (auto &asteroid: asteroids) {
        asteroid->draw(window);
    }
}

void Game::drawMenueScreen() {

}

void Game::drawGameOverScreen() {

}
