//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_APPLICATIONMANAGER_H
#define PROYECTDATOS2_APPLICATIONMANAGER_H

#include "../ImageLoader.h"
#include "../Headers/MainScreen.h"
#include "../Headers/LInkedListFilesHeaders/LinkedListStructured.h"

using namespace sf;
class ApplicationManager {
private:
    sf::RenderWindow * mainWindow; //will store the window
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;
    WindowStatesStack* states;
    LinkedListStructured* supportedKeys;
    void createWindow();
    void initWindowState();
    void initKeys();

public:
    ApplicationManager();
    virtual ~ApplicationManager();
    void run();
    void endApp();
    void updateDt();
    void update();
    void render();
    void updateEvents();

};


#endif //PROYECTDATOS2_APPLICATIONMANAGER_H
