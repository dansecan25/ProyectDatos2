//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_GAMESCREEN_H
#define PROYECTDATOS2_GAMESCREEN_H
#include "../Headers/WindowState.h"

class GameScreen : public WindowState{
private:

public:
    GameScreen(sf::RenderWindow * window);
    ~GameScreen();
    void endState();
    void gameUpdate(const float& dt);
    void gameRender(sf::RenderTarget * target= nullptr);

};


#endif //PROYECTDATOS2_GAMESCREEN_H
