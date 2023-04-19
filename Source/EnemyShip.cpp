//
// Created by dansecan on 11/03/23.
//

#include "../Headers/EnemyShip.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace std;

/**
 * @brief constructor to create an enemy
 */
EnemyShip::EnemyShip() {
    this->id = 0;
}
/**
 * @brief constructor to create an enemy with an id and its type
 */
EnemyShip::EnemyShip(int id,char type, int res) {
    next=NULL;
    this->resistance = res;
    this->alive = true;
    this->id = id;

        switch (type) {
            case '\n': {
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
 * @brief Constructor with only an id
 * @param id int
 */
EnemyShip::EnemyShip(int id){
    next=NULL;
    this->id = id;
}
/**
 * @brief Returns the sprite for the enemy
 * @return sprite
 */
sf::Sprite & EnemyShip::getSprite(){
    return sprite;
}
/**
 * @brief Defines the resistance for the enemies
 * @param resistance int
 */
void EnemyShip::setResistance(int resistance){
    this->resistance = resistance;
}
/**
 * @brief Sets the coordenates for each enemy
 * @param xpos float
 * @param ypos float
 */
void EnemyShip::setLocation(float xpos, float ypos)
{
    sprite.setPosition(xpos,ypos);
}
/**
 * @brief Defines if an enemy is killed
 */
void EnemyShip::kill()
{
    this->alive = false;
}
/**
 * @brief Defines that the enemy is alive
 * @return boolean alive
 */
bool EnemyShip::isAlive()
{
    return alive;
}
/**
 * @brief sets the enemy in the screen
 * @param target RenderTarget pointer
 */
void EnemyShip::draw(sf::RenderTarget * target)
{
    sprite.setTexture(texture);
    target->draw(sprite);
}
/**
 * @brief edits the node's next pointer
 * @param newNext EnemyShip pointer
 */
void EnemyShip::editPointer(EnemyShip *newNext) {
    this->next=newNext;
}
/**
 * @brief returns the enemies id
 * @return id int
 */
int EnemyShip::getId() {
    return id;
}
/**
 * @brief Sets the patterns for enemies
 * @param p string
 */
void EnemyShip::setPattern(string p){
    this->pattern = p;
}
/**
 * @brief Returns the pattern
 * @return pattern
 */
string EnemyShip::getPattern(){
    return pattern;
}
/**
 * @brief Returns the next enemy
 * @return next
 */
EnemyShip* EnemyShip::getNext() {
    return next;
}
