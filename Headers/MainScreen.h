//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_MAINSCREEN_H
#define PROYECTDATOS2_MAINSCREEN_H
#include <SFML/Graphics.hpp>
#include "../Headers/SfmlButton.h"
#include "../ImageLoader.h"
#include "../Headers/WindowState.h"
#include "../Headers/LInkedListFilesHeaders/gameStateStack.h"
#include "../Headers/GameScreen.h"
//#include "../Resources/Images/SpaceBackground.jpg"
using namespace sf;
class MainScreen {
private:
    //SfmlButton * gamestate_btn;
    sf::RenderWindow * mainWindow; //will store the window
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;
    gameStateStack* states;
    void createWindow();
    void initWindowState();

public:
    MainScreen();
    virtual ~MainScreen();
    void run();
    void endApp();
    void updateDt();
    void update();
    void render();
    void updateEvents();

};


#endif //PROYECTDATOS2_MAINSCREEN_H
