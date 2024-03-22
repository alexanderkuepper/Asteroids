//
// Created by Alex on 03.01.2024.
//

#ifndef SHAPEINVADER_PLAYER_H
#define SHAPEINVADER_PLAYER_H


#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "InputManager.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Entity.h"

class Player : public Entity {
private:
    float speed = 300;
public:
    explicit Player(sf::Vector2f position);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;
};


#endif //SHAPEINVADER_PLAYER_H
