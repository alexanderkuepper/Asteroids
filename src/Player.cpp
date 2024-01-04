//
// Created by Alex on 03.01.2024.
//

#include "Player.h"


void Player::update(float deltaTime) {
    sf::Vector2f direction = InputManager::get().getDirection();
    this->position.x += speed * direction.x * deltaTime;
    this->position.y += speed * direction.y * deltaTime;
}

void Player::draw(sf::RenderWindow &window) {
    player.setPosition(this->position);
    window.draw(player);
}

Player::Player(sf::Vector2f position) {
    this->position = position;
    player.setSize(sf::Vector2f(100.f, 100.f));
}
