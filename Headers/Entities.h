//
// Created by dansecan on 30/03/23.
//

#ifndef PROYECTDATOS2_ENTITIES_H
#define PROYECTDATOS2_ENTITIES_H
#include <SFML/Graphics.hpp>
#include <vector> //temporary

class Entities {
public:
    Entities();
    ~Entities();
    virtual void move(const float& dt, const float x, const float y);

    virtual void updateEntity(const float& dt);
    virtual void renderEntity(sf::RenderTarget* target);

protected:
    sf::Sprite* sprite;
    sf::Texture* texture;
    sf::RectangleShape entityShape;
    float movementSpeed;
};


#endif //PROYECTDATOS2_ENTITIES_H
