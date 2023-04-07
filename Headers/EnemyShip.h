//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_ENEMYSHIP_H
#define PROYECTDATOS2_ENEMYSHIP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <math.h>

class EnemyShip {
    EnemyShip();

    unsigned char hit_timer;
    unsigned short x;
    unsigned short y;
    unsigned char type;
    sf::Sprite sprite;
    sf::Sprite texture;

public:
    EnemyShip(unsigned char i_type, unsigned short i_x, unsigned short i_y);

    unsigned char get_hit_timer() const;
    unsigned short get_x() const;
    unsigned short get_y() const;
    void hit();
    void move();
    void update();

    sf::IntRect get_hitbox() const;
};



#endif //PROYECTDATOS2_ENEMYSHIP_H
