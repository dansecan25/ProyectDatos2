//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_BULLET_H
#define PROYECTDATOS2_BULLET_H


#include <array>
#include <SFML/Graphics.hpp>

class Bullet {
    Bullet();

private:
    Bullet* next;

public:
    int impact;
    int id;

    sf::Sprite sprite;
    sf::Texture texture;

    Bullet(int id,int imp);

    Bullet *getNext();
    void editBullet(int imp);
    void editBulletPointer(Bullet *newNext);
    int getImpact();

    //void* operator new(size_t size);
    //void operator delete(void*);
    void setPosition( float x, float y);
    void draw(sf::RenderTarget * target);

    sf::Sprite &getSprite();
    int getId();
    sf::Vector2<float> getPosition();
};

#endif //PROYECTDATOS2_BULLET_H
