//
// Created by monicaegm on 4/6/23.
//

#include "GameModeScreen.h"
#include "GameScreen.h"

GameModeScreen::GameModeScreen(sf::RenderWindow* window,LinkedListStructured* mapStructures,gameStateStack* states)
:WindowState(window, mapStructures,states){
    this->initFonts();
    this->initButtons();
}

GameModeScreen::~GameModeScreen() {
    delete this->easyButton;
    delete this->mediumButton;
    delete this->hardButton;
}

void GameModeScreen::endState() {
    cout<<"Goodbye suckers!"<<endl;
}
void GameModeScreen::updateInput(const float &dt) {
    this->checkForQuit();

}
void GameModeScreen::stateUpdate(const float& dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);
    this->updateButtons();
}

void GameModeScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->renderButtons(target);
}
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
void GameModeScreen::updateButtons() {
    this->easyButton->update(this->positions.posXf, this->positions.posYf);
    if (this->easyButton->isPressed()) {
        cout<<"easy";
        this->states->push(new GameScreen(this->window, this->supportedKeys, this->states));
    }
    this->mediumButton->update(this->positions.posXf, this->positions.posYf);
    if (this->mediumButton->isPressed()) {
        cout<<"medium";
        this->states->push(new GameScreen(this->window, this->supportedKeys, this->states));
    }
    this->hardButton->update(this->positions.posXf, this->positions.posYf);
    if (this->hardButton->isPressed()) {
        cout<<"hard";
        this->states->push(new GameScreen(this->window, this->supportedKeys, this->states));
    }
}
void GameModeScreen::renderButtons(sf::RenderTarget *target) {
    this->easyButton->render(target);
    this->mediumButton->render(target);
    this->hardButton->render(target);

}