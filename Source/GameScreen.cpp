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
void GameScreen::updateKeybinds(const float &dt) {
    this->checkForQuit();
}
void GameScreen::gameUpdate(const float& dt) {
    this->updateKeybinds(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        std::cout<<"A"<<"\n";
}

void GameScreen::gameRender(sf::RenderTarget * target) {

}




