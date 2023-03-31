//
// Created by dansecan on 11/03/23.
//

#include "../Headers/GameScreen.h"

GameScreen::GameScreen(sf::RenderWindow * window):WindowState(window){

}

GameScreen::~GameScreen() {

}
void GameScreen::endState() {
    cout<<"Goodbye suckers!"<<endl;
}
void GameScreen::updateInput(const float &dt) {
    this->checkForQuit();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->player.move(dt, 0,-2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->player.move(dt, 0,2);
    }
}
void GameScreen::stateUpdate(const float& dt) {
    this->updateInput(dt);
    this->player.updateEntity(dt);
}

void GameScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->player.renderEntity(this->window);


}




