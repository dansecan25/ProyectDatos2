//
// Created by dansecan on 27/03/23.
//

#include "../../Headers/LInkedListFilesHeaders/gameStateStack.h"
/**
 * @brief constructor for the node of the stack
 */
StackNodeStates::StackNodeStates(GameScreen* dat) {
    this->data=dat;
    this->link=nullptr;
}
/**
 * @brief set the data of the node
 * @param dat WindowState pointer
 */
void StackNodeStates::setData(GameScreen *dat) {
    this->data=dat;
}
/**
 * @brief gets the WindowState pointer stored in the node
 * @return WindowState pointer
 */
GameScreen *StackNodeStates::getData() {
    return this->data;
}
/**
 * @brief set the pointer to the next object in the stack
 * @param next StackNodeStates pointer
 */
void StackNodeStates::setLink(StackNodeStates *next) {
    this->link=next;
}
/**
 * @brief get the pointer to the next object in the stack
 * @return StackNodeStates pointer
 */
StackNodeStates *StackNodeStates::getLink() {
    return this->link;
}
/**
 * @brief stack constructor
 */
gameStateStack::gameStateStack() {
    top = nullptr;

}
/**
 * @brief pushes an object into the stack
 * @param data
 */
void gameStateStack::push(GameScreen* data){
    auto* temp = new StackNodeStates(data);
    temp->setData(data);
    temp->setLink(top);
    top = temp;


}

/**
 * @brief checks if the stack is empty or not
 * @return true if empty or false if not
 */
bool gameStateStack::isEmpty() const{
    return top == nullptr;
}

/**
 * @brief peeks the top element of the stack
 * @return WindowState pointer
 */
GameScreen* gameStateStack::peek(){
    if (!isEmpty())
        return top->getData();
    else return nullptr;
}

/**
 * @brief delete the top element of the stack
 */
void gameStateStack::pop(){
    StackNodeStates* temp;

    if (top == nullptr) {
        cout << "\nStack Underflow" << endl;
    }
    else {
        temp = top;
        top = top->getLink();
        free(temp);//free the memory
    }
}
/**
 * @brief destructor for the stack
 */
gameStateStack::~gameStateStack() {
    while(this->top!=nullptr){
        StackNodeStates* temp=this->top;
        this->top=temp->getLink();
        temp->setLink(nullptr);
        free(temp);
    }

}
