//
// Created by dansecan on 06/04/23.
//

#include <sstream>
#include "../Headers/MainScreen.h"
#include "../Headers/GameModeScreen.h"

MainScreen::MainScreen(sf::RenderWindow* window, LinkedListStructured* supportedKeys, WindowStatesStack* states,ArduinoManagement* arduino)
: WindowState(window,supportedKeys,states,arduino){
    this->initFonts();
    this->initTitle();
    this->initKeybinds();
    this->initButtons();

}

MainScreen::~MainScreen() {
    delete this->startButton;
    delete this->exitButton;
}
/**
 * @brief updates the event keys pressed actions when input happens
 * @param dt int time
 */
void MainScreen::updateInput(const float &dt) {
}
void MainScreen::initKeybinds() {
    this->keyBinds->insertNode("Move_Up",this->supportedKeys->getNode("W"));
    this->keyBinds->insertNode("Move_Down",this->supportedKeys->getNode("S"));
    this->keyBinds->insertNode("Quit",this->supportedKeys->getNode("Escape"));
}
/**
 * @brief states what should be updated by the current window state
 * @param dt
 */
void MainScreen::stateUpdate(const float &dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);
    this->updateButtons();
}
/**
 * @brief states what the current window state shall draw
 * @param target RenderTarget pointer
 */
void MainScreen::stateRender(sf::RenderTarget *target) {
    if(!target){
        target=this->window;
    }
    this->renderButtons(target);
    this->renderTitle(target);
    //create the title
    sf::Text tempTitle;
    tempTitle.setPosition(430,170);
    tempTitle.setFont(this->font);
    tempTitle.setCharacterSize(30);
    tempTitle.setString("SPACE BATTLE");
    tempTitle.setFillColor(sf::Color::White);

    target->draw(tempTitle);
    //change later to a texture that will be made
    //temporary mouse position
    sf::Text mouseText;
    mouseText.setPosition(this->positions.posXf,this->positions.posYf-50);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(12);
    std::stringstream ss;
    ss<<this->positions.posXf<<" "<<this->positions.posYf<<"\n";
    mouseText.setString(ss.str());
    mouseText.setFillColor(sf::Color::White);

    target->draw(mouseText);
}
/**
 * @brief loads the font to the font attribute
 */
void MainScreen::initFonts() {
    if (!this->font.loadFromFile("../Resources/Fonts/arial.ttf"))
    {
        exit(200); //200 will be the unique code for this space
    }
}
/**
 * @brief defines the buttons that will be created
 */
void MainScreen::initButtons() {
    this->startButton=new SfmlButton(450, 400, 200, 75, &font, "Start Game",
                                     sf::Color(70,70,70,200),
                                     sf::Color(150,150,150,255),
                                     sf::Color(20,20,20,200));
    this->exitButton=new SfmlButton(50, 50, 75, 40, &font, "Exit",
                                     sf::Color(70,70,70,200),
                                     sf::Color(150,150,150,255),
                                     sf::Color(20,20,20,200));
    this->settingButton=new SfmlButton(890, 50, 75, 40, &font, "Settings",
                                     sf::Color(70,70,70,200),
                                     sf::Color(150,150,150,255),
                                     sf::Color(20,20,20,200));

}
/**
 * @brief updates what happens when a button is clicked
 */
void MainScreen::updateButtons() {
    this->startButton->update(this->positions.posXf, this->positions.posYf);
    //here goes when start button is pressed
    if(this->startButton->isPressed()){
        this->states->push(new GameModeScreen(this->window,this->supportedKeys,this->states,this->arduinoControls));
    }
    this->exitButton->update(this->positions.posXf, this->positions.posYf);
    if(this->exitButton->isPressed()){
        this->endState();
    }
    this->settingButton->update(this->positions.posXf, this->positions.posYf);
    if(this->settingButton->isPressed()){
        std::cout<<"pushing settings window"<<"\n";
    }
}

/**
 * @brief draws the buttons on the screen
 * @param target RenderTarget pointer
 */
void MainScreen::renderButtons(sf::RenderTarget *target) const {
    this->startButton->render(target);
    this->exitButton->render(target);
    this->settingButton->render(target);
}
/**
 * @brief defines the title
 */
void MainScreen::initTitle() {
    //this->title.setSize(sf::Vector2f(static_cast<float>(1000),static_cast<float>(60)));
}
/**
 * @brief draws the title
 * @param target RenderTarget pointer
 */
void MainScreen::renderTitle(sf::RenderTarget *target) {
    //this->titleTexture.loadFromFile("../Resources/Images/TitleImage.jpg");
    //this->titleTexture.setTexture(backGroundTexture);
    //this->target.
}





