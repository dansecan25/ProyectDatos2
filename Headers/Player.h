//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_PLAYER_H
#define PROYECTDATOS2_PLAYER_H
#include "../Headers/Entities.h"

class Player :
        public Entities{
public:
    Player(float x, float y, std::string playerTexture);
    ~Player();

private:
    void initVariables();
    void initPlayerData();







};


#endif //PROYECTDATOS2_PLAYER_H
