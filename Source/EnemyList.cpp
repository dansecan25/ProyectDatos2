//
// Created by monicaegm on 4/9/23.
//

#include "EnemyList.h"
#include "../Headers/EnemyShip.h"
using namespace std;

/**
 * @brief constructor of the list of enemies
 */
EnemyList::EnemyList() {
    head= nullptr;
    //len=0;
}
/**
 * Inserts a new enemy in the enemy list
 * * @param enemy enemy node
 */
void EnemyList::insertEnemy(EnemyShip *enemy) {
    if (getHead() == NULL)
    {
        setHead(enemy);
    }
    else
    {
        getLast()->editPointer(enemy);
    }
}
/**
 * Looks if a determined enemy exists in the list
 * @param id id of the enemy
 * @return enemy found
 */
EnemyShip* EnemyList::findEnemy(int id){
    EnemyShip *find =  getHead();
    while((find != NULL) and (find->getId()!=id)){
        find = find->getNext();
    }
    return find;
}
/**
 * Sets the head of the list
 * @param H
 */
void EnemyList::setHead(EnemyShip *H) {
    head = H;
}
/**
 * Returns the head of the list
 * @return head
 */
EnemyShip* EnemyList::getHead() {
    return head;
}
/**
 * Returns the last node of the enemy list
 * @return last
 */
EnemyShip* EnemyList::getLast() {
    EnemyShip *last = getHead();
    while(last->getNext()!=NULL){
        last = last->getNext();
    }
    return last;
}
/**
 * Prints the enemy list with all of its enemies
 * @param n head of the list
 */
void EnemyList::printList(EnemyShip *n){

    if (n != NULL)
    {
        cout << "We have: " << n->getId() <<endl;
        this->printList(n->next);
    }
}
