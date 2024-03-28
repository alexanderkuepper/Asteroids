//
// Created by alex on 21.03.2024.
//

#ifndef SHAPEINVADER_ENTITY_H
#define SHAPEINVADER_ENTITY_H

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

enum Type {
    BULLET, ASTEROID, PLAYER, ENTITY
};

class Entity {
public:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;

    virtual ~Entity();

    virtual void update(float);

    virtual void draw(sf::RenderWindow &);

    virtual Type getType();

    bool collisionCheck(const Entity &) const;
};

#endif //SHAPEINVADER_ENTITY_H