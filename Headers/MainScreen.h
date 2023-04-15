//
// Created by dansecan on 06/04/23.
//

#ifndef PROYECTDATOS2_MAINSCREEN_H
#define PROYECTDATOS2_MAINSCREEN_H
#include "../Headers/SfmlButton.h"
#include "../Headers/GameModeScreen.h"

using namespace std;
class MainScreen
        :public WindowState{
public:
    MainScreen(sf::RenderWindow* window, LinkedListStructured* supportedKeys, WindowStatesStack* states, ArduinoManagement* arduino);
    virtual ~MainScreen();
    SfmlButton * startButton;
    SfmlButton * exitButton;
    SfmlButton * settingButton;

    void updateInput(const float& dt) override;
    void updateButtons();
    void renderButtons(sf::RenderTarget * target) const;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;
private:
    sf::Font font;
    sf::RectangleShape title;
    sf::Texture titleTexture;
    void initFonts();
    void initButtons();
    void initTitle();
    void renderTitle(sf::RenderTarget *target);
    void initKeybinds() override;








};


#endif //PROYECTDATOS2_MAINSCREEN_H
