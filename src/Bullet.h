//
// Created by alex on 21.03.2024.
//

#ifndef SHAPEINVADER_BULLET_H
#define SHAPEINVADER_BULLET_H


#include "Entity.h"

class Bullet : public Entity {
private:
    float speed = 200.;
public:

    explicit Bullet(sf::Vector2f position);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    Type getType() override;

};


#endif //SHAPEINVADER_BULLET_H
