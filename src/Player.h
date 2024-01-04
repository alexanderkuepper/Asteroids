//
// Created by Alex on 03.01.2024.
//

#ifndef SHAPEINVADER_PLAYER_H
#define SHAPEINVADER_PLAYER_H


#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "InputManager.h"

class Player {
private:
    sf::Vector2f position;
    int delta{};
    float speed = 200;
    sf::RectangleShape player;
public:
    explicit Player(sf::Vector2f position);

    void update(float deltaTime);

    void draw(sf::RenderWindow &window);
};


#endif //SHAPEINVADER_PLAYER_H
