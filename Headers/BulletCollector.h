//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_BULLETCOLLECTOR_H
#define PROYECTDATOS2_BULLETCOLLECTOR_H


#include "Bullet.h"

class BulletCollector {

public:
    Bullet * head;
    BulletCollector();

    void addBullet(int id, int imp);
    void printCollector(Bullet *n);
    void setHead(Bullet *H);

    Bullet *getHead();

    Bullet *getLast();

    Bullet *findBullet(int data);

    void deleteBullet(int data);
};


#endif //PROYECTDATOS2_BULLETCOLLECTOR_H
