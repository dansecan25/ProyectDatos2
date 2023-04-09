//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_GAMESCREEN_H
#define PROYECTDATOS2_GAMESCREEN_H
#include "../Headers/WindowState.h"
#include "SfmlButton.h"
#include <iostream>
using namespace std;
class GameScreen
        : public WindowState{
private:
    Player *player;
    sf::RectangleShape backGround;
    sf::Texture backGroundTexture;
    void initObjects();
    void initVariables();
    void initKeybinds() override;
    void initTextures();
    void initPlayer();
public:
    explicit GameScreen(sf::RenderWindow * window, LinkedListStructured* mapStructures, WindowStatesStack* states);
    ~GameScreen() override;
    void updateInput(const float& dt) override;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;









};


#endif //PROYECTDATOS2_GAMESCREEN_H
