//
// Created by monicaegm on 4/9/23.
//

#include "EnemyList.h"
#include "../Headers/EnemyShip.h"
using namespace std;

/**
 * @brief constructor of the linkedList
 */
EnemyList::EnemyList() {
    head= nullptr;
    //len=0;
}
/**
 * @brief inserts a node into the linked list
 * @param cDat char pointer
 * @param dat int
 */
void EnemyList::insertEnemy(const int id,float speed) {
    EnemyShip *enemy = new EnemyShip(id, speed);
    if (getHead() == NULL)
    {
        setHead(enemy);
    }
    else
    {
        getLast()->editPointer(enemy);
    }
}

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
 * Looks if a determined node exists in the list
 * @param data
 * @return
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
 * @return
 */
EnemyShip* EnemyList::getHead() {
    return head;
}
/**
 * Returns the last node of the list
 * @return
 */
EnemyShip* EnemyList::getLast() {
    EnemyShip *last = getHead();
    while(last->getNext()!=NULL){
        last = last->getNext();
    }
    return last;
}
/**
 * Prints the list with all of its nodes
 * @param n
 */
void EnemyList::printList(EnemyShip *n){

    if (n != NULL)
    {
        cout << "We have: " << n->getId() <<endl;
        this->printList(n->next);
    }
}
