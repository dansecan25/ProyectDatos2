//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_ENEMYSHIP_H
#define PROYECTDATOS2_ENEMYSHIP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <math.h>
#include "Bullet.h"

class EnemyShip {
public:
    //constructor sets ID number, loads sprite
    EnemyShip();
    EnemyShip(int id,float speed);
    sf::Sprite & getSprite();
    void setLocation(float,float);

    void kill();
    bool isAlive();
    float getSpeed() const;
    void draw(sf::RenderTarget * target);
    void setResistance(int resistance);

    void editPointer(EnemyShip *newNext);
    int getId();
    EnemyShip *getNext();

    EnemyShip* next;
    sf::Sprite sprite;
    sf::Texture texture;
    bool alive;
    float speed;
    int id;
    int resistance;

private:


};

    /*
    static constexpr unsigned short SCREEN_WIDTH = 320;
    static constexpr unsigned char BASE_SIZE = 16;
    static constexpr unsigned char ENEMY_MOVE_SPEED = 2;
    char direction;
    unsigned char hit_timer;
    unsigned short x;
    unsigned short y;
    unsigned char type;

    sf::Sprite enemy_sprite;
    sf::Texture enemy_texture;

public:
    EnemyShip(unsigned char i_type, unsigned short i_x, unsigned short i_y);

    unsigned char get_health() const;
    unsigned char get_hit_timer() const;
    unsigned char get_type() const;

    unsigned short get_x() const;
    unsigned short get_y() const;

    void hit();
    void move();
    void update();

    sf::IntRect get_hitbox() const;
}; */



#endif //PROYECTDATOS2_ENEMYSHIP_H
