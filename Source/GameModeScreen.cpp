//
// Created by monicaegm on 4/6/23.
//

#include "../Headers/GameModeScreen.h"
#include "../Headers/GameScreen.h"

/**
 * @brief GameModeScreen state constructor
 * @param window RenderWindow pointer
 * @param mapStructures LinkedListStructured pointer
 * @param states gameStatesStack pointer
 */
GameModeScreen::GameModeScreen(sf::RenderWindow* window, LinkedListStructured* mapStructures, WindowStatesStack* states)
:WindowState(window, mapStructures,states){
    this->initFonts();
    this->initButtons();
}
/**
 * @brief GameModeScreen constructor
 */
GameModeScreen::~GameModeScreen() {
    delete this->easyButton;
    delete this->mediumButton;
    delete this->hardButton;
}
/**
 * @brief updates the inputs events on the current state of the window
 * @param dt const float reference
 */
void GameModeScreen::updateInput(const float &dt) {

}
/**
 * @brief updates the events in the window
 * @param dt const float reference
 */
void GameModeScreen::stateUpdate(const float& dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);
    this->updateButtons();
}
/**
 * @brief states what will be drawn in the window
 * @param target RenderTarget pointer
 */
void GameModeScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->renderButtons(target);
}
/**
 * @brief stores the accepted keys in the linked list
 */
void GameModeScreen::initKeybinds() {
}
/**
 * @brief loads the font to the font attribute
 */
void GameModeScreen::initFonts() {
    if (!this->font.loadFromFile("../Resources/Fonts/arial.ttf"))
    {
        exit(200);
    }
}
/**
 * @brief inits the buttons
 */
void GameModeScreen::initButtons() {
    this->easyButton = new SfmlButton(50, 200, 200, 75, &font, "Easy Mode",
                                      sf::Color(70, 70, 70, 200),
                                      sf::Color(150, 150, 150, 255),
                                      sf::Color(20, 20, 20, 200));
    this->mediumButton = new SfmlButton(100, 300, 200, 75, &font, "Medium Mode",
                                        sf::Color(70, 70, 70, 200),
                                        sf::Color(150, 150, 150, 255),
                                        sf::Color(20, 20, 20, 200));
    this->hardButton = new SfmlButton(150, 400, 200, 75, &font, "Hard Mode",
                                      sf::Color(70, 70, 70, 200),
                                      sf::Color(150, 150, 150, 255),
                                      sf::Color(20, 20, 20, 200));
}
/**
 * @brief shows the buttons
 */
void GameModeScreen::updateButtons() {
    this->easyButton->update(this->positions.posXf, this->positions.posYf);
    if (this->easyButton->isPressed()) {
        this->states->pop();
        this->states->push(new GameScreen(this->window, this->supportedKeys, this->states, 1));
    }
    this->mediumButton->update(this->positions.posXf, this->positions.posYf);
    if (this->mediumButton->isPressed()) {
        this->states->pop();
        this->states->push(new GameScreen(this->window, this->supportedKeys, this->states, 2));
    }
    this->hardButton->update(this->positions.posXf, this->positions.posYf);
    if (this->hardButton->isPressed()) {
        this->states->pop();
        this->states->push(new GameScreen(this->window, this->supportedKeys, this->states, 3));
    }
}
/**
 * @brief draws the buttons
 * @param target Rendertarget pointer
 */
void GameModeScreen::renderButtons(sf::RenderTarget *target) {
    this->easyButton->render(target);
    this->mediumButton->render(target);
    this->hardButton->render(target);
}