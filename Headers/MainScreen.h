//
// Created by dansecan on 06/04/23.
//

#ifndef PROYECTDATOS2_MAINSCREEN_H
#define PROYECTDATOS2_MAINSCREEN_H
#include "../Headers/WindowState.h"
#include "../Headers/SfmlButton.h"
#include "../Headers/GameScreen.h"
#include "../Headers/GameModeScreen.h"

using namespace std;
class MainScreen
        :public WindowState{
public:
    MainScreen(sf::RenderWindow* window, LinkedListStructured* supportedKeys,gameStateStack* states);
    virtual ~MainScreen();
    SfmlButton * startButton;
    SfmlButton * exitButton;

    void endState();
    void updateInput(const float& dt);
    void updateButtons();
    void renderButtons(sf::RenderTarget * target);
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;
private:
    sf::RectangleShape backGround;
    sf::Font font;
    void initFonts();
    void initButtons();
    virtual void initKeybinds() override;
};


#endif //PROYECTDATOS2_MAINSCREEN_H
