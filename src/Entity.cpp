//
// Created by alex on 23.03.2024.
//

#include "Entity.h"

bool Entity::collisionCheck(const Entity& entity) const {
    return this->sprite.getGlobalBounds().intersects(entity.sprite.getGlobalBounds());
}