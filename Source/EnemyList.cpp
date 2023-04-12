//
// Created by monicaegm on 4/9/23.
//

#include "../Headers/EnemyList.h"
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
int EnemyList::deleteEnemy(int id){
    EnemyShip *find = getHead();
    EnemyShip *before=NULL;
    if(find->getId()==id){
        setHead(getHead()->getNext());
    } else {
        while((find!=NULL) and (find->getId()!=id)){
            before=find;
            find=find->getNext();
        }
        if (find!=NULL){
            before->editPointer(find->getNext());
        }
    }
    delete find;
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

/**
 * Returns the number of enemies in the list
 */
int EnemyList::lenEnemyList(EnemyShip *n){
    int i = 0;
    if (n != NULL)
    {
        i++;
        this->lenEnemyList(n->next);
    }
    return i;
}