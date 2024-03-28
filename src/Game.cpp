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
    if (asteroidClock.getElapsedTime().asSeconds() > 0.1) {
        entities.push_back(std::make_unique<Asteroid>());
        asteroidClock.restart();
    }
}

void Game::clearOffscreenEntities() {
    entities.erase(
            std::remove_if(entities.begin(), entities.end(), [](auto &entity) {
                if (auto *asteroid = dynamic_cast<Asteroid *>(entity.get())) {
                    if(asteroid->position.y > height) {
                        return asteroid->position.y > height;
                    }
                } else if (auto *bullet = dynamic_cast<Bullet *>(entity.get()))
                    return bullet->position.y < 0;
                return false;
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
        if (auto *asteroid = dynamic_cast<Asteroid *>(entity.get())) {
            asteroid->update(deltaTime);
            if (entities[0]->collisionCheck(*asteroid)) {
                gameState = GameState::gameOverScreen;
                entities.clear();
            }
        }
        if (auto *bullet = dynamic_cast<Bullet *>(entity.get())) {
            bullet->update(deltaTime);
        }
    }
    removeCollidedEntities();
}

void Game::updateMenueScreen() {

}

void Game::updateGameOverScreen() {
    if (InputManager::restart()) {
        gameState = GameState::gamePlay;
    }
}

void Game::drawGamePlay() {
    player.draw(window);
    for (auto &entity: entities) {
        if (auto *asteroid = dynamic_cast<Asteroid *>(entity.get())) {
            asteroid->draw(window);
        } else if (auto *bullet = dynamic_cast<Bullet *>(entity.get())) {
            bullet->draw(window);
        }
    }
}

void Game::drawMenueScreen() {

}

void Game::drawGameOverScreen() {

}

void Game::shootBullet() {
    entities.push_back(std::make_unique<Bullet>(getShootPosition()));
}

sf::Vector2f Game::getShootPosition() {
    return sf::Vector2f{player.position.x + player.sprite.getGlobalBounds().width / 2, player.position.y};
}

void Game::removeCollidedEntities() {
    /*std::vector<Asteroid *> asteroids;
    std::vector<Bullet *> bullets;
    for(auto &entity : entities) {
        if (auto *asteroid = dynamic_cast<Asteroid *>(entity.get())) {
            asteroids.push_back(asteroid);
        } else if (auto *bullet = dynamic_cast<Bullet *>(entity.get())) {
            bullets.push_back(bullet);
        }
    }

    for (auto asteroidIter = asteroids.begin(); asteroidIter != asteroids.end(); ++asteroidIter) {
        for (auto bulletIter = bullets.begin(); bulletIter != bullets.end(); ++bulletIter) {
            if ((*asteroidIter)->collisionCheck(**bulletIter)) {
                asteroids.erase(asteroidIter);
                bullets.erase(bulletIter);
                return;
            }
        }
    }*/
}
