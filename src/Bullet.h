//
// Created by alex on 21.03.2024.
//

#ifndef SHAPEINVADER_BULLET_H
#define SHAPEINVADER_BULLET_H


#include "Entity.h"

class Bullet : public Entity {
public:
    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

};


#endif //SHAPEINVADER_BULLET_H
