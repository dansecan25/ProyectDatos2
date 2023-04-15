//
// Created by dansecan on 11/03/23.
//

#include <cstring>
#include "../Headers/Bullet.h"

/**
 * @brief constructor to create a bullet
 */
Bullet::Bullet() {
    id = 0;
    impact = 0;
    speed = 0;
    next = NULL;

}
/**
 * @brief Constructor to create a bullet with defined impact
 * @param int imp
 */
Bullet::Bullet(int id,int imp,float sp){
    this->id = id;
    this->impact = imp;
    this->speed = sp;
    this->next=NULL;
}

/**
 * @brief Edits the bullets impact
 * @param imp int
 */
void Bullet::editBullet(int imp) {
    this->impact = imp;
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
 * @return
 */
int Bullet::getImpact() {
    return impact;
}
/**
 * @brief Returns the next bullet pointer
 * @return
 */
Bullet* Bullet::getNext() {
    return next;
}

Bullet* Bullet::moveBullet(sf::Vector2f pos){
    this->direction = pos;
    shape.move(direction * speed);
}
void Bullet::draw(sf::RenderTarget * target){
    shape.setRadius(5);
    target->draw(shape);
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