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
GameModeScreen::GameModeScreen(sf::RenderWindow* window, LinkedListStructured* mapStructures, WindowStatesStack* states,ArduinoManagement* arduino)
:WindowState(window, mapStructures,states, arduino){
    this->initFonts();
    this->initButtons();
    this->arduinoControls->sendWindowState("Settings\n");
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
    static sf::Clock inputClock;
    if (inputClock.getElapsedTime().asSeconds() > 0.5f) {
        // Reset the clock
        inputClock.restart();
        std::string valuePotence = to_string(this->arduinoControls->getPotentiometerValue());
        textPotentiometer.setString(valuePotence);
    }
}
/**
 * @brief states what will be drawn in the window
 * @param target RenderTarget pointer
 */
void GameModeScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->renderBulletSpeed();

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
    Strategies* strat= new Strategies();
    if (this->easyButton->isPressed()) {
        this->states->pop();
        this->arduinoControls->sendWindowState("DoneSettings\n");
        this->states->push(new GameScreen(this->window, this->supportedKeys, this->states, 1,this->arduinoControls,strat));
    }
    this->mediumButton->update(this->positions.posXf, this->positions.posYf);
    if (this->mediumButton->isPressed()) {
        this->states->pop();
        this->arduinoControls->sendWindowState("DoneSettings\n");
        this->states->push(new GameScreen(this->window, this->supportedKeys, this->states, 2, this->arduinoControls,strat));
    }
    this->hardButton->update(this->positions.posXf, this->positions.posYf);
    if (this->hardButton->isPressed()) {
        this->states->pop();
        this->arduinoControls->sendWindowState("DoneSettings\n");
        this->states->push(new GameScreen(this->window, this->supportedKeys, this->states, 3,this->arduinoControls,strat));
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
/**
 * @brief draws texts in the window
 */
void GameModeScreen::renderBulletSpeed() {
    textPotentiometer.setPosition(790,170);
    textPotentiometer.setFont(this->font);
    textPotentiometer.setCharacterSize(30);
    textPotentiometer.setFillColor(sf::Color::White);
    sf::Text potenceText;
    potenceText.setPosition(750,140);
    potenceText.setFont(this->font);
    potenceText.setCharacterSize(30);
    potenceText.setFillColor(sf::Color::White);
    potenceText.setString("Potence Value");
    this->window->draw(textPotentiometer);
    this->window->draw(potenceText);
}
