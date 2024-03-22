//
// Created by alex on 21.03.2024.
//

#ifndef SHAPEINVADER_ENTITY_H
#define SHAPEINVADER_ENTITY_H

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Entity {
public:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;

    virtual void update(float) = 0;

    virtual void draw(sf::RenderWindow &) = 0;
};

#endif //SHAPEINVADER_ENTITY_H