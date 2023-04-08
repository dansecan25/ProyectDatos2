//
// Created by dansecan on 27/03/23.
//

#ifndef PROYECTDATOS2_WINDOWSTATE_H
#define PROYECTDATOS2_WINDOWSTATE_H
#include "../Headers/Entities.h"
#include "../Headers/LInkedListFilesHeaders/LinkedListStructured.h"
#include "../Headers/LInkedListFilesHeaders/WindowStatesStack.h"
//#include <iostream>
struct mousePositions{
    int posXi;
    int posYi;
    unsigned int posXu;
    unsigned int posYu;
    float posXf;
    float posYf;
};
class WindowState {
protected:
    WindowStatesStack* states;
    mousePositions positions{};
    sf::RenderWindow* window;
    LinkedListStructured* supportedKeys;
    LinkedListStructured* keyBinds;
    std::vector<sf::Texture> textures;//change to a linked list
    bool quit;
    virtual void initKeybinds()=0;
public:
    WindowState(sf::RenderWindow* window, LinkedListStructured* mapStructures, WindowStatesStack* states);
    virtual ~WindowState();
    [[nodiscard]] const bool& getQuit() const;
    virtual void updateInput(const float& dt)=0;
    virtual void stateUpdate(const float& dt)=0;
    virtual void stateRender(sf::RenderTarget * target)=0;
    void endState();
    void updateMousePosScreen();










};


#endif //PROYECTDATOS2_WINDOWSTATE_H
