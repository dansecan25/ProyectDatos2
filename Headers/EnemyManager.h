//
// Created by monicaegm on 4/6/23.
//

#ifndef PROYECTDATOS2_ENEMYMANAGER_H
#define PROYECTDATOS2_ENEMYMANAGER_H


#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <random>
#include "Bullet.h"
#include "EnemyShip.h"

class EnemyManager {
    unsigned short move_pause;
    unsigned short move_timer;

    std::uniform_int_distribution<unsigned short> shoot_distribution;

    std::vector<EnemyShip> enemies;

    static constexpr unsigned char BASE_SIZE = 16;
public:
    EnemyManager();
    void setLevel(int mode);
    void draw(sf::RenderTarget * target);
    void update();
};


#endif //PROYECTDATOS2_ENEMYMANAGER_H
