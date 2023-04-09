//
// Created by dansecan on 27/03/23.
//

#include "../../Headers/LInkedListFilesHeaders/texturesRoutes.h"
/**
 * @brief constructore of the Node of the map
 */
texturesStructNode::texturesStructNode() {
    data.dataKey= " ";
    data.textureData= " ";
}
/**
 * @brief destructor of the Node of the map
 */
texturesStructNode::~texturesStructNode() {

}
/**
 * @brief gets the character stored in the structure
 * @return string
 */
std::string texturesStructNode::getCharacter() const {
    return data.dataKey;
}
/**
 * @brief returns the sf::Texture inside the node
 * @return sf::Texture
 */
std::string texturesStructNode::getTextureData() const {
    return data.textureData;
}
/**
 * @brief adds the data to the node
 * @param cDat string
 * @param dat string
 */
void texturesStructNode::setData(std::string cDat, std::string textureDat) {
    data.dataKey=cDat;
    data.textureData=textureDat;
}
/**
 * @brief secondary constructor for the node
 */
texturesStructNode::texturesStructNode(std::string cDat, std::string textureDat) {
    this->data.textureData=textureDat;
    this->data.dataKey=cDat;
}
/**
 * @brief sets the node that goes next
 * @param newNext structuresNode pointer
 */
void texturesStructNode::setNext(texturesStructNode * newNext) {
    this->next=newNext;
}
/**
 * @brief returns the pointer to the next node
 * @return pointer to next structuresNode
 */
texturesStructNode *texturesStructNode::getNext() {
    return next;
}

/**
 * @brief constructor of the linkedList
 */
texturesRoutes::texturesRoutes() {
    head= nullptr;
    len=0;
}
/**
 * @brief inserts a node into the linked list
 * @param cDat char pointer
 * @param dat int
 */
void texturesRoutes::insertNode(std::string cDat, std::string textureDat) {
    auto* newNode = new texturesStructNode(cDat, textureDat);
    newNode->setNext(nullptr);
    if(head== nullptr){

        head=newNode;

        len++;
    }else{
        texturesStructNode* temp= head;
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
std::string texturesRoutes::getNode(std::string key) {
    texturesStructNode* temp;
    temp=head;
    while(temp!= nullptr){
        if(temp->getCharacter()==key){
            return temp->getTextureData();
        }
        temp=temp->getNext();
    }
    return {};
}
/**
 * @brief deletes a node in the list
 * @param key string
 */
void texturesRoutes::deleteNode(const std::string key) {
    texturesStructNode * temp1=head,*temp2= head;
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
int texturesRoutes::getLen() const {
    return this->len;
}
/**
 * @brief deletes the last node in the list
 */
void texturesRoutes::deleteLast() {
    texturesStructNode * temp1=head;
    if(len==0) {
        len=0;
        return;
    }else if(len==1){
        head=nullptr;
        delete temp1;
        len--;
    }else{
        while(temp1!= nullptr){
            texturesStructNode* nextTemp=temp1->getNext();
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