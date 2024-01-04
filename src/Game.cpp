//
// Created by Alex on 02.01.2024.
//

#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode(800, 600), "Shape Invader");
    window.setFramerateLimit(60);
}

void Game::loadContent() {

}

void Game::update() {
    deltaTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    player.update(deltaTime);
    quitGame();
}

void Game::draw() {
    window.clear();
    player.draw(window);
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
