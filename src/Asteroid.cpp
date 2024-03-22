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
    float x = std::rand() % Game::width - sprite.getTexture()->getSize().x;
    position = sf::Vector2f{x,-60};
    sprite.setPosition(position);
}
