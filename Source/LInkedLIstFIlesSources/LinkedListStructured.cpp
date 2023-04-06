//
// Created by dansecan on 30/03/23.
//

#include "../../Headers/LInkedListFilesHeaders/LinkedListStructured.h"
/**
 * @brief constructore of the Node of the list
 */
structuresNode::structuresNode() {
    data.dataKey= " ";
    data.integerDat= 0;

    //this->next= nullptr;
}
/**
 * @brief destructor of the Node of the list
 */
structuresNode::~structuresNode() {

}
/**
 * @brief gets the character stored in the structure
 * @return string
 */
std::string structuresNode::getCharacter() {
    return data.dataKey;
}
/**
 * @brief returns the integer inside the node
 * @return int
 */
int structuresNode::getInteger() {
    return data.integerDat;
}
/**
 * @brief sets the character in the structure
 * @param cDat pointer to a character
 */
void structuresNode::setChar(std::string cDat) {
    data.dataKey=cDat;
}
/**
 * @brief set the int in the structure
 * @param dat int
 */
void structuresNode::setInt(int dat) {
    data.integerDat=dat;
}
/**
 * @brief adds the data to the noda
 * @param cDat
 * @param dat
 */
void structuresNode::setData(std::string cDat, int dat) {
    data.dataKey=cDat;
    data.integerDat=dat;
}
/**
 * @brief secondary constructor for the node
 */
structuresNode::structuresNode(std::string cDat, int dat) {
    this->data.integerDat=dat;
    this->data.dataKey=cDat;
}
/**
 * @brief sets the node that goes next
 * @param newNext structuresNode pointer
 */
void structuresNode::setNext(structuresNode * newNext) {
    this->next=newNext;
}
/**
 * @brief returns the pointer to the next node
 * @return pointer to next structuresNode
 */
structuresNode *structuresNode::getNext() {
    return next;
}

/**
 * @brief constructor of the linkedList
 */
LinkedListStructured::LinkedListStructured() {
    head= nullptr;
    len=0;
}
/**
 * @brief inserts a node into the linked list
 * @param cDat char pointer
 * @param dat int
 */
void LinkedListStructured::insertNode(std::string cDat, int dat) {
    auto* newNode = new structuresNode(cDat, dat);
    newNode->setNext(nullptr);
    if(head== nullptr){

        head=newNode;

        len++;
    }else{
        structuresNode* temp= head;
        while(temp->getNext()!= nullptr){
            temp=temp->getNext();
        }
        temp->setNext(newNode);
        len++;
    }
}
/**
 * @brief obtains a node from a specific key
 * @param key char pointer
 */
int LinkedListStructured::getNode(std::string key) {
    structuresNode* temp;
    temp=head;
    while(temp!= nullptr){
        if(temp->getCharacter()==key){
            return temp->getInteger();
        }
        temp=temp->getNext();
    }
    return -10;
}
/**
 * @brief deletes a node in the list
 * @param key
 */
void LinkedListStructured::deleteNode(std::string key) {
    structuresNode * temp1=head,*temp2= head;
    if(len==0) {
        len=0;
        return;
    }else if(temp1->getCharacter()==key){//if the key is in the head
        head=head->getNext();
        delete temp1;
        len--;
        return;
    }else{
        for(int i=0; i<len;i++){
            if(temp1->getCharacter()==key){
                temp2->setNext(temp1->getNext());
                delete temp1;
                len--;
                break;
            }else{
                temp2=temp1;
                temp1=temp1->getNext();
            }
        }
    }

}
/**
 * @brief returns the lenght of the list
 * @return len int
 */
int LinkedListStructured::getLen() {
    return this->len;
}
/**
 * @brief deletes the last node in the list
 */
void LinkedListStructured::deleteLast() {
    structuresNode * temp1=head;
    if(len==0) {
        len=0;
        return;
    }else if(len==1){
        head=nullptr;
        delete temp1;
        len--;
    }else{
        while(temp1!= nullptr){
            structuresNode* nextTemp=temp1->getNext();
            if(nextTemp->getNext()== nullptr){
                temp1->setNext(nextTemp->getNext());
                nextTemp->setNext(nullptr);
                delete nextTemp;
                len--;
                return;
            }
            temp1=nextTemp;
            nextTemp=nextTemp->getNext();
        }
    }
}
