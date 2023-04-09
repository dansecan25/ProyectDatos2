//
// Created by dansecan on 11/03/23.
//

#include "../Headers/EnemyShip.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <math.h>

#include "../Headers/EnemyShip.h"
using namespace std;
/**
 * returns an exception
 */
struct MyException : public exception {
    const char * what () const throw () {
        return "A C++ Exception";
    }
};
/**
 * constructor to create an enemy
 */
EnemyShip::EnemyShip() {
    this->speed = 0;
    this->id = 0;
}
/**
 * constructor to create an enemy with an id and its speed
 */
EnemyShip::EnemyShip(int id,float speed) {
    next=NULL;

    this->alive = true;
    this->id = id;
    this->speed = speed;

    // Load an enemy texture
    if(!texture.loadFromFile("../Resources/Images/Enemy0.png"))
        throw MyException();
    //scale sprite and set texture
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.8,0.8));
    }


sf::Sprite & EnemyShip::getSprite()
{
    return sprite;
}

void EnemyShip::setResistance(int resistance){
    this->resistance = resistance;
}
void EnemyShip::setLocation(float xpos, float ypos)
{
    sprite.setPosition(xpos,ypos);
}

void EnemyShip::kill()
{
    this->alive = false;
}

bool EnemyShip::isAlive()
{
    return alive;
}

void EnemyShip::draw(sf::RenderTarget * target)
{
    //set texture
    sprite.setTexture(texture);
    //draw
    target->draw(sprite);
}

float EnemyShip::getSpeed() const
{
    return speed;
}
/**
 * edits the node next pointer
 * @param newNext
 */
void EnemyShip::editPointer(EnemyShip *newNext) {
    this->next=newNext;
}
/**
 * returns the nodes data
 * @return
 */
int EnemyShip::getId() {
    return id;
}
/**
 * Returns the next node pointer
 * @return
 */
EnemyShip* EnemyShip::getNext() {
    return next;
}
/*
unsigned char EnemyShip::get_hit_timer() const
{
    return hit_timer;
}
unsigned char EnemyShip::get_type() const
{
    return type;
}

unsigned short EnemyShip::get_x() const
{
    return x;
}

unsigned short EnemyShip::get_y() const
{
    return y;
}
void EnemyShip::move()
{
    if (0 != direction)
    {
        if ((1 == direction && x == SCREEN_WIDTH - 2 * BASE_SIZE) || (-1 == direction && x == BASE_SIZE))
        {
            //Once we reach the edge, we start moving down until we reach the next row.
            direction = 0;

            y += ENEMY_MOVE_SPEED;
        }
        else
        {
            //Moving horizontally.
            x = std::clamp<short>(x + ENEMY_MOVE_SPEED * direction, BASE_SIZE, SCREEN_WIDTH - 2 * BASE_SIZE);
        }
    }
    else
    {
        y = std::min<short>(y + ENEMY_MOVE_SPEED, BASE_SIZE * ceil(y / static_cast<float>(BASE_SIZE)));

        if (y == BASE_SIZE * ceil(y / static_cast<float>(BASE_SIZE)))
        {
            //Moving in a snake pattern. We use the modulo operator to decide whether to move left or right.
            direction = 0 == (y / BASE_SIZE) % 2 ? -1 : 1;
        }
    }
}
 */
