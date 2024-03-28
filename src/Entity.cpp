//
// Created by alex on 23.03.2024.
//

#include "Entity.h"

bool Entity::collisionCheck(const Entity &entity) const {
    return this->sprite.getGlobalBounds().intersects(entity.sprite.getGlobalBounds());
}

void Entity::update(float) {

}

void Entity::draw(sf::RenderWindow &) {

}

Type Entity::getType() {
    return ENTITY;
}


Entity::~Entity() = default;
