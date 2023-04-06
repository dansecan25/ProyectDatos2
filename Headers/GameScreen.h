//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_GAMESCREEN_H
#define PROYECTDATOS2_GAMESCREEN_H
#include "../Headers/WindowState.h"
#include <iostream>
using namespace std;
class GameScreen
        : public WindowState{
private:
    Entities player;

    void initKeybinds() override;
public:
    explicit GameScreen(sf::RenderWindow * window,LinkedListStructured* mapStructures,gameStateStack* states);
    ~GameScreen() override;
    void endState()override;
    void updateInput(const float& dt) override;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;

};


#endif //PROYECTDATOS2_GAMESCREEN_H
