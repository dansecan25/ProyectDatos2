//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_BULLET_H
#define PROYECTDATOS2_BULLET_H


#include <array>

class Bullet {
    Bullet();
    static constexpr unsigned char BASE_SIZE = 16;
    static constexpr unsigned short SCREEN_HEIGHT = 180;
    static constexpr unsigned short SCREEN_WIDTH = 320;

    bool dead;

    float real_x;
    float real_y;
    float step_x;
    float step_y;

    short x;
    short y;

    //We also use this struct in the Player class. But the player's bullets don't have a tail. So it may seem a bit redundant. But I'm too lazy to fix it.
    std::array<short, 3> previous_x;
    std::array<short, 3> previous_y;
    Bullet(float i_step_x, float i_step_y, short i_x, short i_y);

    void update();
};


#endif //PROYECTDATOS2_BULLET_H
