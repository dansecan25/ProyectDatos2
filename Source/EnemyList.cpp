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
}
/**
 * @brief Inserts a new enemy in the enemy list
 * * @param enemy EnemyShip pointer
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
 * @briefLooks if a determined enemy exists in the list
 * @param id int
 * @return find node
 */
EnemyShip* EnemyList::findEnemy(int id){
    EnemyShip *find =  getHead();
    while((find != NULL) and (find->getId()!=id)){
        find = find->getNext();
    }
    return find;
}
/**
 * @briefSets the head of the list
 * @param H EnemyShip pointer
 */
void EnemyList::setHead(EnemyShip *H) {
    head = H;
}
/**
 * @brief Returns the head of the list
 * @return head node
 */
EnemyShip* EnemyList::getHead() {
    return head;
}
/**
 * @brief Returns the last node of the enemy list
 * @return last node
 */
EnemyShip* EnemyList::getLast() {
    EnemyShip *last = getHead();
    while(last->getNext()!=NULL){
        last = last->getNext();
    }
    return last;
}
/**
 * @brief Deletes enemies from the list
 * @param id int
 * @return deleted node
 */
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
 * @brief Prints the enemy list with all of its enemies
 * @param n EnemyShip pointer
 */
void EnemyList::printList(EnemyShip *n){

    if (n != NULL)
    {
        cout << "We have: " << n->getId() <<endl;
        this->printList(n->next);
    }
}
/**
 * Counts how many enemies there are
 * @param n EnemyShip pointer
 * @return i int
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