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

public:
    explicit GameScreen(sf::RenderWindow * window);
    ~GameScreen() override;
    void endState()override;
    void updateKeybinds(const float& dt) override;
    void gameUpdate(const float& dt) override;
    void gameRender(sf::RenderTarget * target) override;

};


#endif //PROYECTDATOS2_GAMESCREEN_H
