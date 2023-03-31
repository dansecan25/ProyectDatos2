//
// Created by dansecan on 27/03/23.
//

#include "../Headers/WindowState.h"

WindowState::WindowState(sf::RenderTarget* window) {
    this->window=window;
    this->quit=false;
}

WindowState::~WindowState() {

}
/**
 * @brief checks if the escape key is pressed to set the boolean as true
 */
void WindowState::checkForQuit() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ //when escape key is pressed, game closes
        this->quit=true;
    }
}

const bool &WindowState::getQuit() const {
    return this->quit;
}
