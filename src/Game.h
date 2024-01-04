//
// Created by Alex on 02.01.2024.
//

#ifndef SHAPEINVADER_GAME_H
#define SHAPEINVADER_GAME_H


#include "InputManager.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Player.h"


class Game {
private:
    sf::RenderWindow window;
    sf::Event event{};
    Player player{{200,200}};
    sf::Clock clock;
    float deltaTime{};
    void quitGame();
public:
    bool isRunning = true;
    Game();
    void loadContent();
    void update();
    void draw();
};


#endif //SHAPEINVADER_GAME_H
