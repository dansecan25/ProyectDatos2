//
// Created by dansecan on 11/03/23.
//

#include <iostream>
#include "../Headers/BulletCollector.h"
using namespace std;

/**
 * @brief constructor to create a bullet collector
 */
BulletCollector::BulletCollector() {
    head = NULL;
}
/**
 * @brief Sets the head of the collector
 * @param H Bullet pointer
 */
void BulletCollector::setHead(Bullet *H) {
    head = H;
}
/**
 * @brief Returns the head of the collector
 * @return head Bullet
 */
Bullet* BulletCollector::getHead() {
    return head;
}
/**
 * @brief Returns the last bullet of the collector
 * @return last Bullet
 */
Bullet* BulletCollector::getLast() {
    Bullet *last = getHead();
    while(last->getNext()!=NULL){
        last = last->getNext();
    }
    return last;
}
/**
 * @brief Adds a new bullet to the collector
 * @param id int
 * @param imp int
 * @param sp float
 */
void BulletCollector::addBullet (int id, int imp){
    Bullet *n=new Bullet(id,imp);
    if (getHead() == NULL)
    {
        setHead(n);
    }
    else
    {
        getLast()->editBulletPointer(n);
    }
}
/**
 * @brief Prints the collector with all of its bullets
 * @param n Bullet pointer
 */
void BulletCollector::printCollector(Bullet *n){
    if (n != NULL)
    {
        cout << n->getId() <<endl;
        this->printCollector(n->getNext());
    }
}
/**
 * @brief Deletes a bullet from the collector
 * @param data int
 */
void BulletCollector::deleteBullet(int data){
    Bullet *find = getHead();
    Bullet *before=NULL;
    if(find ->getImpact()==data){
        setHead(getHead()->getNext());
    } else {
        while((find!=NULL) and (find->getImpact()!=data)){
            before=find;
            find=find->getNext();
        }
        if (find!=NULL){
            before->editBulletPointer(find->getNext());
        }
    }
    delete find;
}
/**
 * @brief Looks if a determined node exists in the list
 * @param data int
 * @return find Bullet
 */
Bullet* BulletCollector::findBullet(int data){
    Bullet *find =  getHead();
    while((find != NULL) and (find->getId()!=data)){
        find = find->getNext();
    }
    return find;
}

