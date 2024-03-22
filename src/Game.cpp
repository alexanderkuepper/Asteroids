//
// Created by Alex on 02.01.2024.
//

#include <iostream>
#include <memory>
#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode(width, height), "Shape Invader");
    window.setFramerateLimit(100);
}

void Game::update() {
    float deltaTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    player.update(deltaTime);
    generateAsteroid();
    removeAsteroid();
    for (auto &asteroid: asteroids) {

        asteroid->update(deltaTime);
    }
    quitGame();
}

void Game::draw() {
    window.clear();
    player.draw(window);
    for (auto &asteroid: asteroids) {
        asteroid->draw(window);
    }
    window.display();
}

void Game::quitGame() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            isRunning = false;
        }
    }
}

void Game::generateAsteroid() {
    if (asteroidClock.getElapsedTime().asSeconds() > 0.1) {
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
