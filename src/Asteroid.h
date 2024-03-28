//
// Created by alex on 21.03.2024.
//

#ifndef SHAPEINVADER_ASTEROID_H
#define SHAPEINVADER_ASTEROID_H


#include "Entity.h"

class Asteroid : public Entity {
private:
    float speed = 200;
    sf::Vector2<float> getRandomPosition();
public:

    Asteroid();

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    Type getType() override;

};


#endif //SHAPEINVADER_ASTEROID_H
