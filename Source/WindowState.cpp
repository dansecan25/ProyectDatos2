//
// Created by dansecan on 27/03/23.
//

#include "../Headers/WindowState.h"

/**
 * @brief constructor of the window state manager class
 * @param window RednerWindow pointer
 * @param mapStructures LinkedListStructures pointer
 * @param states gameStateStack pointer
 */
WindowState::WindowState(sf::RenderWindow* window, LinkedListStructured* mapStructures,gameStateStack* states) {
    this->keyBinds=new LinkedListStructured();
    this->supportedKeys=mapStructures;
    this->window=window;
    this->positions= {0,0,0,0,0,0};
    this->states=states;
    this->quit=false;
}

WindowState::~WindowState() {
    while(keyBinds->getLen()>0){
        keyBinds->deleteLast();
    }
    delete keyBinds;
}
/**
 * @brief checks if the escape key is pressed to set the boolean as true
 */
void WindowState::checkForQuit() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Quit")))){ //when escape key is pressed, game closes
        std::cout<<"Quitting"<<std::endl;
        this->quit=true;
    }
}
/**
 * @brief checks if the window has been called to quit
 * @return true if quit and false if not to quit
 */
const bool &WindowState::getQuit() const {
    return this->quit;
}
/**
 * @brief updates all the mouse positions that are stored
 */
void WindowState::updateMousePosScreen() {
    this->positions.posXi = sf::Mouse::getPosition().x;
    this->positions.posYi = sf::Mouse::getPosition().y;

    this->positions.posXu=sf::Mouse::getPosition(*this->window).x;
    this->positions.posYu=sf::Mouse::getPosition(*this->window).y;

    this->positions.posXf=this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)).x;
    this->positions.posYf=this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)).y;





}
