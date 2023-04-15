//
// Created by monicaegm on 4/9/23.
//

#ifndef PROYECTDATOS2_ENEMYLIST_H
#define PROYECTDATOS2_ENEMYLIST_H
#include<iostream>
#include "EnemyShip.h"


class EnemyList {
public:
    EnemyList();
    void setHead(EnemyShip *H);
    EnemyShip *getHead();
    EnemyShip *getLast();

    void insertEnemy(EnemyShip *enemy);
    EnemyShip *findEnemy(int id);
    void deleteEnemy(int d);

    void printList(EnemyShip *n);
    int lenEnemyList(EnemyShip *n);

private:
    EnemyShip* head;
};


#endif //PROYECTDATOS2_ENEMYLIST_H
