//
// Created by dansecan on 11/03/23.
//

#include "../Headers/Player.h"

Player::Player(float x, float y, std::string playerTexture) {
    this->initVariables();
    this->initPlayerData();
    this->giveTexture(playerTexture);
    this->setPosition(x,y);
    this->getPosition();
}

Player::~Player() {

}

void Player::initVariables() {

}

void Player::initPlayerData() {

}
