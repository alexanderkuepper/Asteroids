//
// Created by Alex on 03.01.2024.
//

#include "Player.h"
#include "Game.h"


void Player::update(float deltaTime) {
    sf::Vector2f direction = InputManager::get().getDirection();
    float newPositionX = position.x + speed * direction.x * deltaTime;
    if (Game::width < newPositionX) {
        position.x = -(float) sprite.getTexture()->getSize().x;
    } else if (newPositionX < -(float) sprite.getTexture()->getSize().x) {
        position.x = Game::width;
    } else {
        position.x = newPositionX;
    }
    position.y += speed * direction.y * deltaTime;
    sprite.setPosition(this->position);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

Player::Player() {
    texture.loadFromFile("content/player.png");
    sprite.setTexture(texture);
    setPlayerStartPosition();
}

void Player::setPlayerStartPosition() {
    float x = Game::width / 2.;
    float y = Game::height / 2.;
    this->position = sf::Vector2f{x,y};
    sprite.setPosition(this->position);
}

Type Player::getType() {
    return Type::PLAYER;
}
