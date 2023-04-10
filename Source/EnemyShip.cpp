//
// Created by dansecan on 11/03/23.
//

#include "../Headers/EnemyShip.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace std;

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
EnemyShip::EnemyShip(int id,float speed,char type) {
    next=NULL;

    this->alive = true;
    this->id = id;
    this->speed = speed;

    cout<<" \n type \n"<< type;
        switch (type) {
            case '\n': {
                cout<<" no pattern ";
                break;
            }
            case '0': {
                if(!texture.loadFromFile("../Resources/Images/Enemy0.png"))
                    cout<<"Error loading texture for enemy";
                sprite.setTexture(texture);
                sprite.scale(sf::Vector2f(0.03,0.03));
                break;
            }
            case '1': {
                if(!texture.loadFromFile("../Resources/Images/Enemy1.png"))
                    cout<<"Error loading texture for enemy";
                sprite.setTexture(texture);
                sprite.scale(sf::Vector2f(0.02,0.02));
                break;
            }
            case '2': {
                if(!texture.loadFromFile("../Resources/Images/Enemy2.png"))
                    cout<<"Error loading texture for enemy";
                sprite.setTexture(texture);
                sprite.scale(sf::Vector2f(0.12,0.12));
                break;
            }
        }
    }

/**
 * Returns the sprite for the enemy
 * @return sprite
 */
sf::Sprite & EnemyShip::getSprite(){
    return sprite;
}
/**
 * Defines the resistance for the enemies
 * @param resistance int
 */
void EnemyShip::setResistance(int resistance){
    this->resistance = resistance;
}
/**
 * Sets the coordenates for each enemy
 * @param xpos
 * @param ypos
 */
void EnemyShip::setLocation(float xpos, float ypos)
{
    sprite.setPosition(xpos,ypos);
}
/**
 * Defines if an enemy is killed
 */
void EnemyShip::kill()
{
    this->alive = false;
}
/**
 * Defines that the enemy is alive
 * @return
 */
bool EnemyShip::isAlive()
{
    return alive;
}
/**
 * Sets the enemy in the screen
 * @param target
 */
void EnemyShip::draw(sf::RenderTarget * target)
{
    sprite.setTexture(texture);
    target->draw(sprite);
}
/**
 * Returns the speed of the enemy
 * @return
 */
float EnemyShip::getSpeed() const
{
    return speed;
}
/**
 * edits the node's next pointer
 * @param newNext
 */
void EnemyShip::editPointer(EnemyShip *newNext) {
    this->next=newNext;
}
/**
 * returns the enemies id
 * @return
 */
int EnemyShip::getId() {
    return id;
}
/**
 * Returns the next enemy
 * @return
 */
EnemyShip* EnemyShip::getNext() {
    return next;
}
/**
 * Sets the pattern of enemies to be drawn
 * @param type
 */
basic_string<char> EnemyShip::makePattern(int mode){
    switch (mode){ //pattern for showing enemies

        case 0: {
            this->level_sketch = "0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0";

            break;
        }
        case 1: {
            this->level_sketch = "000000\n000000\n000000";

            break;
        }
        case 2: {
            this->level_sketch = "101010\n010101\n101010";

            break;
        }
        case 3: {
            this->level_sketch = "001100\n002200\n112211";

            break;
        }
        case 4: {
            this->level_sketch = "2222222222222222\n1111111111111111\n1010101010101010\n0101010101010101";

            break;
        }
        case 5: {
            this->level_sketch = "0000000000000000\n2222222222222222\n1111111111111111\n1111111111111111";

            break;
        }
        case 6: {
            this->level_sketch = "2121212121212121\n1212121212121212\n2121212121212121\n1212121212121212";

            break;
        }
        case 7: {
            this->level_sketch = "2222222222222222\n2222222222222222\n2222222222222222\n2222222222222222";
        }
    }
    return level_sketch;
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
