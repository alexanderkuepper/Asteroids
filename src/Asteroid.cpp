//
// Created by alex on 21.03.2024.
//

#include "Asteroid.h"
#include "Game.h"

void Asteroid::update(float deltaTime) {
    position.y += speed * deltaTime;
    sprite.setPosition(this->position);
}

void Asteroid::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

Asteroid::Asteroid() {
    texture.loadFromFile("content/asteroid.png");
    sprite.setTexture(texture);
    position = getRandomPosition();
    sprite.setPosition(position);
}

sf::Vector2<float> Asteroid::getRandomPosition() {
    float x = std::rand() % Game::width - sprite.getTexture()->getSize().x;
    return sf::Vector2f{x,-60};
}

Type Asteroid::getType() {
    return Type::ASTEROID;
}
