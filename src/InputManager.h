//
// Created by Alex on 04.01.2024.
//

#ifndef SHAPEINVADER_INPUTMANAGER_H
#define SHAPEINVADER_INPUTMANAGER_H


#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"

class InputManager {
private:
    InputManager();

    static InputManager inputManager;
    sf::Vector2f direction;
    bool fireBullet = false;
public:
    InputManager(const InputManager &) = delete;

    static InputManager &get();

    sf::Vector2f getDirection();

    static bool restart();

    bool shoot();
};


#endif //SHAPEINVADER_INPUTMANAGER_H
