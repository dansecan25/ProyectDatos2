//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_BULLET_H
#define PROYECTDATOS2_BULLET_H


#include <array>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class Bullet {
    Bullet();

private:
    Bullet* next;

public:
    int impact;
    int id;

    sf::CircleShape shape;
    sf::Vector2f direction;
    sf::Texture texture;

    float speed;

    Bullet(int id,int imp,float sp);

    Bullet *getNext();
    void editBullet(int imp);
    void editBulletPointer(Bullet *newNext);
    int getImpact();

    //void* operator new(size_t size);
    //void operator delete(void*);
    Bullet *moveBullet(sf::Vector2f pos);

    void draw(sf::RenderTarget *target);
};

#endif //PROYECTDATOS2_BULLET_H
