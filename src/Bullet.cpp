//
// Created by alex on 21.03.2024.
//

#include "Bullet.h"

void Bullet::update(float deltaTime) {
    position.y -= speed * deltaTime;
    sprite.setPosition(this->position);
}

void Bullet::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

Bullet::Bullet(sf::Vector2f position) {
    texture.loadFromFile("content/bullet.png");
    sprite.setTexture(texture);
    this->position = position;
    sprite.setPosition(position);
}

Type Bullet::getType() {
    return Type::BULLET;
}
