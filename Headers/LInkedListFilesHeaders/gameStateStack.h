//
// Created by dansecan on 27/03/23.
//

#ifndef PROYECTDATOS2_GAMESTATESTACK_H
#define PROYECTDATOS2_GAMESTATESTACK_H
#include <SFML/Graphics.hpp>
#include "../../Headers/GameScreen.h"
#include <iostream>

using namespace std;
class StackNodeStates{
public:
    explicit StackNodeStates(GameScreen* dat);
    void setData(GameScreen* dat);
    GameScreen* getData();
    void setLink(StackNodeStates* next);
    StackNodeStates* getLink();
private:
    GameScreen * data;
    StackNodeStates* link;

};

class gameStateStack {
public:
    gameStateStack();
    ~gameStateStack();
    void push(GameScreen* dat);
    GameScreen* peek();
    void pop();
    bool isEmpty();
    StackNodeStates* top;

private:

};


#endif //PROYECTDATOS2_GAMESTATESTACK_H
