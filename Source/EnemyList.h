//
// Created by monicaegm on 4/9/23.
//

#ifndef PROYECTDATOS2_ENEMYLIST_H
#define PROYECTDATOS2_ENEMYLIST_H
#include<iostream>
#include "../Headers/EnemyShip.h"


class EnemyList {
public:
    EnemyList();
    EnemyShip *findEnemy(int id);
    void setHead(EnemyShip *H);
    EnemyShip *getHead();
    EnemyShip *getLast();

    void printList(EnemyShip *n);

    void insertEnemy(EnemyShip *enemy);

private:
    EnemyShip* head;
};


#endif //PROYECTDATOS2_ENEMYLIST_H
