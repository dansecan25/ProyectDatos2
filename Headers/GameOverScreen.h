//
// Created by monicaegm on 4/18/23.
//

#ifndef PROYECTDATOS2_GAMEOVERSCREEN_H
#define PROYECTDATOS2_GAMEOVERSCREEN_H
#include "WindowState.h"
#include "SfmlButton.h"
#include <iostream>


class GameOverScreen : public WindowState{
public:
    explicit GameOverScreen(sf::RenderWindow * window, LinkedListStructured* mapStructures, WindowStatesStack* states);
    ~GameOverScreen() override;
    void updateInput(const float& dt) override;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;
    void initKeybinds() override;

    sf::Font font;

    void initFonts();

    void renderText(sf::RenderTarget *target);
};


#endif //PROYECTDATOS2_GAMEOVERSCREEN_H
