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
    MainScreen(sf::RenderWindow* window, LinkedListStructured* supportedKeys, WindowStatesStack* states);
    virtual ~MainScreen();
    SfmlButton * startButton;
    SfmlButton * exitButton;
    SfmlButton * settingButton;

    void updateInput(const float& dt) override;
    void updateButtons();
    void renderButtons(sf::RenderTarget * target) const;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;
    void updateEventsSpecial(sf::Event event) override;
private:
    sf::Font font;
    sf::RectangleShape title;
    sf::Texture titleTexture;
    sf::RectangleShape entry;
    sf::Text playerName;
    std::string playerInput;
    bool typing;
    void initFonts();
    void initButtons();
    void initTitle();
    void initEntry();
    void updateEntry(sf::Event event);
    void renderTitle(sf::RenderTarget *target);
    void initKeybinds() override;








};


#endif //PROYECTDATOS2_MAINSCREEN_H
