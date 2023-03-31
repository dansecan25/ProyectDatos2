//
// Created by dansecan on 30/03/23.
//

#ifndef PROYECTDATOS2_LINKEDLISTSTRUCTURED_H
#define PROYECTDATOS2_LINKEDLISTSTRUCTURED_H
#include<iostream>
struct interiorData{
    std::string dataKey;
    int integerDat;
};

class structuresNode{
public:
    structuresNode();
    structuresNode(std::string, int);
    ~structuresNode();
    std::string getCharacter();
    int getInteger();
    void setChar(std::string cDat);
    void setInt(int dat);
    void setData(std::string cDat="", int dat=0);
    void setNext(structuresNode*);
    structuresNode* getNext();
private:
    interiorData data;
    structuresNode* next;


};

class LinkedListStructured {
public:
    LinkedListStructured();
    void insertNode(std::string,int);
    int getNode(std::string);
    void deleteNode(std::string);
    int getLen();
    void deleteLast();

private:
    structuresNode* head;
    int len;
};


#endif //PROYECTDATOS2_LINKEDLISTSTRUCTURED_H
