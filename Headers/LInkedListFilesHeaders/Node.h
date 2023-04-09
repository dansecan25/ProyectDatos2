//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_NODE_H
#define PROYECTDATOS2_NODE_H
#include <iostream>

class Node {
private:

public:
    int data;
    Node* next;
    Node();
    Node(int dat);
    void editNode(int dat);
    void editNode(Node* newNext);
    int getData();
    Node* getNext();
    void* operator new(size_t size);
    void operator delete(void*);

};

#endif //PROYECTDATOS2_NODE_H
