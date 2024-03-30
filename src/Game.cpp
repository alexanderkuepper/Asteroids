//
// Created by Alex on 02.01.2024.
//

#include <memory>
#include <iostream>
#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode{width, height}, "Shape Invader");
    window.setFramerateLimit(100);
    font.loadFromFile("content/font.ttf");
    text.setFont(font);
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
    if (asteroidClock.getElapsedTime().asSeconds() > 0.1) {
        entities.push_back(std::make_unique<Asteroid>());
        asteroidClock.restart();
    }
}

void Game::clearOffscreenEntities() {
    entities.erase(
            std::remove_if(entities.begin(), entities.end(), [](auto &entity) {
                if(entity->getType() == Type::ASTEROID) {
                    return entity->position.y > height;
                } else if(entity->getType() == Type::BULLET) {
                    return entity->position.y < 0;
                } else {
                    return false;
                }

            }), entities.end()
    );
}




void Game::quitGame() {
    window.close();
    isRunning = false;
}

void Game::updateGamePlay() {
    player.update(deltaTime);
    generateAsteroid();
    clearOffscreenEntities();
    if (InputManager::get().shoot()) {
        shootBullet();
    }
    for (auto &entity: entities) {
        entity->update(deltaTime);
        if (entity->getType() == Type::ASTEROID && player.collisionCheck(*entity)) {
            gameState = GameState::gameOverScreen;
            entities.clear();
            player.setPlayerStartPosition();
            return;
        }
    }
    removeCollidedEntities();
}

void Game::updateMenueScreen() {
    if (InputManager::restart()) {
        gameState = GameState::gamePlay;
    }
    setText("Game Start\n\tPress A");
}

void Game::updateGameOverScreen() {
    if (InputManager::restart()) {
        gameState = GameState::gamePlay;
    }
    setText("Game Over\n\tPress A");
}

void Game::drawGamePlay() {
    player.draw(window);
    for (auto &entity: entities) {
        entity->draw(window);
    }
}

void Game::drawMenueScreen() {
    window.draw(text);
}

void Game::drawGameOverScreen() {
    window.draw(text);
}

void Game::shootBullet() {
    entities.push_back(std::make_unique<Bullet>(getShootPosition()));
}

sf::Vector2f Game::getShootPosition() {
    return sf::Vector2f{player.position.x + player.sprite.getGlobalBounds().width / 2, player.position.y};
}

void Game::removeCollidedEntities() {
    for (auto asteroidIter = entities.begin(); asteroidIter != entities.end(); ++asteroidIter) {
        for (auto bulletIter = entities.begin(); bulletIter != entities.end(); ++bulletIter) {
            if ((*asteroidIter)->getType() != (*bulletIter)->getType() && (*asteroidIter)->collisionCheck(**bulletIter)) {
                std::iter_swap(bulletIter, entities.end() - 2);
                std::iter_swap(asteroidIter, entities.end() - 1);
                entities.erase(entities.end() -2, entities.end());
                return;
            }
        }
    }
}

void Game::setText(const std::string& textString) {
    text.setString(textString);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setPosition(width / 2.0f, height / 2.0f);
}


