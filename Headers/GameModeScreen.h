//
// Created by monicaegm on 4/6/23.
//

#ifndef PROYECTDATOS2_GAMEMODESCREEN_H
#define PROYECTDATOS2_GAMEMODESCREEN_H
#include "../Headers/WindowState.h"
#include "SfmlButton.h"
#include <iostream>
using namespace std;

class GameModeScreen
        : public WindowState{
private:
    SfmlButton * easyButton;
    SfmlButton * mediumButton;
    SfmlButton * hardButton;
    void initKeybinds() override;

public:
    explicit GameModeScreen(sf::RenderWindow * window, LinkedListStructured* mapStructures, WindowStatesStack* states);
    ~GameModeScreen() override;
    void updateInput(const float& dt) override;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;

    void initButtons();
    sf::Font font;
    void initFonts();
    void renderButtons(sf::RenderTarget *target);
    void updateButtons();
};



#endif //PROYECTDATOS2_GAMEMODESCREEN_H
