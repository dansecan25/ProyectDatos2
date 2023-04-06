//
// Created by dansecan on 11/03/23.
//

#include "../Headers/GameScreen.h"

GameScreen::GameScreen(sf::RenderWindow* window,LinkedListStructured* mapStructures,gameStateStack* states)
:WindowState(window, mapStructures,states){
    this->initKeybinds();

}

GameScreen::~GameScreen() {

}
void GameScreen::endState() {
    cout<<"Goodbye suckers!"<<endl;
}
void GameScreen::updateInput(const float &dt) {
    this->checkForQuit();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Move_Up")))){
        this->player.move(dt, 0,-2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Move_Down")))){
        this->player.move(dt, 0,2);
    }
}
void GameScreen::stateUpdate(const float& dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);
    this->player.updateEntity(dt);
}

void GameScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->player.renderEntity(this->window);


}

void GameScreen::initKeybinds() {
    this->keyBinds->insertNode("Move_Up",this->supportedKeys->getNode("W"));
    this->keyBinds->insertNode("Move_Down",this->supportedKeys->getNode("S"));
    this->keyBinds->insertNode("Quit",this->supportedKeys->getNode("Escape"));
}




