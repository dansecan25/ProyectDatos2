//
// Created by dansecan on 27/03/23.
//

#ifndef PROYECTDATOS2_WINDOWSTATESTACK_H
#define PROYECTDATOS2_WINDOWSTATESTACK_H
#include <SFML/Graphics.hpp>
#include "../../Headers/WindowState.h"
#include <iostream>

using namespace std;
class StackNodeStates{
public:
    StackNodeStates(WindowState* dat);
    void setData(WindowState* dat);
    WindowState* getData();
    void setLink(StackNodeStates* next);
    StackNodeStates* getLink();
private:
    WindowState * data;
    StackNodeStates* link;

};

class windowStateStack {
public:
    windowStateStack();
    void push(WindowState* dat);
    WindowState* peek();
    void pop();
    bool isEmpty();

private:
    StackNodeStates* top;
};


#endif //PROYECTDATOS2_WINDOWSTATESTACK_H
