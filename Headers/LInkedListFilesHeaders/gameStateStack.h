//
// Created by dansecan on 27/03/23.
//

#ifndef PROYECTDATOS2_GAMESTATESTACK_H
#define PROYECTDATOS2_GAMESTATESTACK_H
#include <SFML/Graphics.hpp>
#include <iostream>
class WindowState;
class StackNodeStates{
public:
    explicit StackNodeStates(WindowState * dat);
    void setData(WindowState* dat);
    WindowState* getData();
    void setLink(StackNodeStates* next);
    StackNodeStates* getLink();
private:
    WindowState * data;
    StackNodeStates* link;

};

class gameStateStack {
public:
    gameStateStack();
    ~gameStateStack();
    void push(WindowState* dat);
    WindowState* peek();
    void pop();
    [[nodiscard]] bool isEmpty() const;
    StackNodeStates* top;


};


#endif //PROYECTDATOS2_GAMESTATESTACK_H
