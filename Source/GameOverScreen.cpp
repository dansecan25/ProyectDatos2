//
// Created by monicaegm on 4/18/23.
//

#include "../Headers/GameOverScreen.h"

/**
 * @brief GameOverScreen state constructor
 * @param window RenderWindow pointer
 * @param mapStructures LinkedListStructured pointer
 * @param states gameStatesStack pointer
 */
GameOverScreen::GameOverScreen(sf::RenderWindow* window, LinkedListStructured* mapStructures, WindowStatesStack* states)
        :WindowState(window, mapStructures,states){
    this->initFonts();

}
/**
 * @brief constructor to state GameOverScreen
 */
GameOverScreen::~GameOverScreen() {

}
/**
 * @brief updates the inputs events on the current state of the window
 * @param dt const float reference
 */
void GameOverScreen::updateInput(const float &dt) {

}
/**
 * @brief updates the events in the window
 * @param dt const float reference
 */
void GameOverScreen::stateUpdate(const float& dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);
}
/**
 * @brief states what will be drawn in the window
 * @param target RenderTarget pointer
 */
void GameOverScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->renderText(target);
}
/**
 * @brief loads the font to the font attribute
 */
void GameOverScreen::initFonts() {
    if (!this->font.loadFromFile("../Resources/Fonts/arial.ttf"))
    {
        exit(200);
    }
}
/**
 * @brief draws the text
 * @param target Rendertarget pointer
 */
void GameOverScreen::renderText(sf::RenderTarget *target) {
    sf::Text text ("Game Over!",font, 50);
    text.setPosition(317.f, 315.f);
    window->draw(text);
}
/**
 * @brief stores the accepted keys in the linked list
 */
void GameOverScreen::initKeybinds() {
}