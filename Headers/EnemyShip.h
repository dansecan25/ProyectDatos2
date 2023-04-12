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
using namespace std;

class EnemyShip {
public:
    EnemyShip();
    EnemyShip(int id,float speed, char mode);

    EnemyShip(int id);

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

    string level_sketch;
    string pattern;

    void setPattern(string p);

    string getPattern();
};
#endif //PROYECTDATOS2_ENEMYSHIP_H
