//
// Created by dansecan on 27/03/23.
//

#include "../../Headers/LInkedListFilesHeaders/windowStateStack.h"
/**
 * @brief constructor for the node of the stack
 */
StackNodeStates::StackNodeStates(WindowState* dat) {
    this->data=dat;
    this->link=NULL;
}
/**
 * @brief set the data of the node
 * @param dat WindowState pointer
 */
void StackNodeStates::setData(WindowState *dat) {
    this->data=dat;
}
/**
 * @brief gets the WindowState pointer stored in the node
 * @return WindowState pointer
 */
WindowState *StackNodeStates::getData() {
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
windowStateStack::windowStateStack() {
    top = NULL;
}
/**
 * @brief pushes an object into the stack
 * @param data
 */
void windowStateStack::push(WindowState* data){
    StackNodeStates* temp = new StackNodeStates(data);

    // Check if stack (heap) is full, if it is, crashes and reports an overflow
    if (!temp) {
        cout << "\nStack Overflow";
        exit(1);
    }
    temp->setData(data);
    temp->setLink(top);
    top = temp;
}

/**
 * @brief checks if the stack is empty or not
 * @return true if empty or false if not
 */
bool windowStateStack::isEmpty(){
    return top == nullptr;
}

/**
 * @brief peeks the top element of the stack
 * @return WindowState pointer
 */
WindowState* windowStateStack::peek(){
    if (!isEmpty())
        return top->getData();
    else return nullptr;
}

/**
 * @brief delete the top element of the stack
 */
void windowStateStack::pop(){
    StackNodeStates* temp;

    if (top == NULL) {
        cout << "\nStack Underflow" << endl;
    }
    else {
        temp = top;
        top = top->getLink();
        free(temp);//free the memory
    }
}