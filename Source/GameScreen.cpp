//
// Created by dansecan on 11/03/23.
//

#include "../Headers/GameScreen.h"
/**
 * @brief gamesScreen state constructor
 * @param window RenderWindow pointer
 * @param mapStructures LinkedListStructured pointer
 * @param states gameStatesStack pointer
 */
GameScreen::GameScreen(sf::RenderWindow* window, LinkedListStructured* mapStructures, WindowStatesStack* states)
:WindowState(window, mapStructures,states){
    this->initVariables();
    this->initObjects();
    this->initKeybinds();
    this->initTextures();
    this->initPlayer();

}
GameScreen::~GameScreen() {
    delete player;
}
/**
 * @brief updates the inputs events on the current state of the window
 * @param dt const float reference
 */
void GameScreen::updateInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Move_Up")))){
        this->player->move(dt, 0,-2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Move_Down")))){
        this->player->move(dt, 0,2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Quit")))){
        this->endState();
    }
}
/**
 * @brief updates the events in the window
 * @param dt const float reference
 */
void GameScreen::stateUpdate(const float& dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);
    this->player->updateEntity(dt);
}
/**
 * @brief states what will be drawn in the window
 * @param target RenderTarget pointer
 */
void GameScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->player->renderEntity(target);

}
/**
 * @brief stores the accepted keys in the linked list
 */
void GameScreen::initKeybinds() {
    this->keyBinds->insertNode("Move_Up",this->supportedKeys->getNode("W"));
    this->keyBinds->insertNode("Move_Down",this->supportedKeys->getNode("S"));
    this->keyBinds->insertNode("Quit",this->supportedKeys->getNode("Escape"));
}
/**
 * @brief init the background objects, GUI
 */
void GameScreen::initObjects() {
    //this->backGround.setSize(sf::Vector2f(static_cast<float>(1000),static_cast<float>(60)));
    //this->backGroundTexture.loadFromFile("../Resources/Images/GUI.jpg");
    //this->backGround.setTexture(backGroundTexture);

}
/**
 * @brief inits the variables
 */
void GameScreen::initVariables() {


}

void GameScreen::initTextures() {
    this->textures->insertNode("PlayerTexture","../Resources/Images/SpaceShipPlayer.png");
}

void GameScreen::initPlayer() {
    std::string route=this->textures->getNode("PlayerTexture");
    this->player=new Player(50, 310,route);
}


