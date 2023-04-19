//
// Created by dansecan on 11/03/23.
//

#include <cstring>
#include "../Headers/Bullet.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

/**
 * @brief constructor to create a bullet
 */
Bullet::Bullet() {
    id = 0;
    next = NULL;
}
/**
 * @brief Constructor to create a bullet with defined impact
 * @param int imp
 */
Bullet::Bullet(int id,int imp){
    this->id = id;
    this->impact = imp;
    this->next=NULL;

    texture.loadFromFile("../Resources/Images/bullet.png");
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.05,0.05));
}
/**
 * @brief Edits the bullets id
 * @param id int
 */
void Bullet::editBullet(int id) {
    this->id = id;
}
/**
 * @brief edits the bullet next pointer
 * @param newNext Bullet pointer
 */
void Bullet::editBulletPointer(Bullet *newNext) {
    this->next = newNext;
}
/**
 * @brief returns the bullets impact
 * @return impact
 */
int Bullet::getImpact() {
    return impact;
}
/**
 * @brief Returns the next bullet pointer
 * @return next
 */
Bullet* Bullet::getNext() {
    return next;
}
/**
 * @brief returns the enemies id
 * @return id int
 */
int Bullet::getId() {
    return id;
}
/**
 * @brief sets the position for the bullet
 * @param float posx
 * @param float posy
 */
void Bullet::setPosition( float posx, float posy){
        sprite.setPosition(posx, posy);
}
/**
 * @brief draws the bullet in screen
 * @param target RenderTarget pointer
 */
void Bullet::draw(sf::RenderTarget * target){
    sprite.setTexture(texture);
    target->draw(sprite);
}
/**
 * @brief Returns the position for the bullet
 * @return position vector
 */
sf::Vector2<float> Bullet::getPosition(){
    return sprite.getPosition();
}
/**
 * @brief Returns the sprite for the bullet
 * @return sprite
 */
sf::Sprite & Bullet::getSprite(){
    return sprite;
}
/**
 * @brief Overloads new operator to asign recycled memory
 * @param size
 * @return
 */
 /*
void* Bullet::operator new(size_t size){
    return Collector::getInstance()->asignMemory(size);
    //check if in  collector there is a recycled pointer that it can use to recyle a memory space to use or use the
    //global new operator to assign memory
}
  */
/**
 * @brief overloades delete operator to recyle memory
 * @param nodeToDelete
 */
 /*
void Bullet::operator delete(void* nodeToDelete){
    //add the pointer to the collector list
    Collector::getInstance()->recycleMemory(nodeToDelete);
}
*/