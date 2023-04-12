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
 * Constructor with only an id
 * @param id int
 */
EnemyShip::EnemyShip(int id){
    next=NULL;
    this->id = id;
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
 * Sets the patterns for enemies
 * @param p
 */
void EnemyShip::setPattern(string p){
    this->pattern = p;
}
/**
 * Returns the pattern
 * @return pattern
 */
string EnemyShip::getPattern(){
    return pattern;
}
/**
 * Returns the next enemy
 * @return
 */
EnemyShip* EnemyShip::getNext() {
    return next;
}
