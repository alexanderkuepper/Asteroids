//
// Created by Alex on 04.01.2024.
//

#include "InputManager.h"


InputManager InputManager::inputManager;

InputManager &InputManager::get() {
    return inputManager;
}

sf::Vector2f InputManager::getDirection() {
    direction.x = 0;
    direction.y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        direction.y = -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction.x = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        direction.y = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        direction.x = -1;
    }
    return direction;
}

InputManager::InputManager() = default;
