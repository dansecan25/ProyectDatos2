//
// Created by dansecan on 06/04/23.
//

#include <sstream>
#include "../Headers/MainScreen.h"

MainScreen::MainScreen(sf::RenderWindow* window, LinkedListStructured* supportedKeys, WindowStatesStack* states)
: WindowState(window,supportedKeys,states){
    this->initFonts();
    this->initTitle();
    this->initKeybinds();
    this->initButtons();
    this->initEntry();

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
    target->draw(entry);
    target->draw(playerName);
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
    this->startButton=new SfmlButton(385, 400, 200, 75, &font, "Start Game",
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
        this->states->push(new GameModeScreen(this->window,this->supportedKeys,this->states));
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
    //create the title
    sf::Text tempTitle;
    tempTitle.setPosition(380,170);
    tempTitle.setFont(this->font);
    tempTitle.setCharacterSize(30);
    tempTitle.setString("SPACE BATTLE");
    tempTitle.setFillColor(sf::Color::White);

    target->draw(tempTitle);
    //this->titleTexture.loadFromFile("../Resources/Images/TitleImage.jpg");
    //this->titleTexture.setTexture(backGroundTexture);
    //this->target.
}

void MainScreen::initEntry() {
    this->entry.setSize(sf::Vector2f(static_cast<float>(200),static_cast<float>(30)));
    this->entry.setPosition(385,300);
    this->entry.setFillColor(sf::Color::White);
    this->playerInput="Name";
    this->playerName.setFont(font);
    this->playerName.setString(playerInput);
    this->playerName.setPosition(385,303);
    this->playerName.setCharacterSize(20);
    this->playerName.setFillColor(sf::Color::Black);
    this->typing=false;
}
/**
 * @brief updates the events on the window
 * @param event sf::Event
 */
void MainScreen::updateEventsSpecial(sf::Event event) {
    this->updateEntry(event);
}
/**
 * @brief updates the entry text
 * @param event sf::Event
 */
void MainScreen::updateEntry(sf::Event event) {
    //sets the typing variable to true if the entry box was clicked
    if(this->entry.getGlobalBounds().contains(positions.posXf,positions.posYf)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->typing=true;
        }
    }
    if(!this->entry.getGlobalBounds().contains(positions.posXf,positions.posYf)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(this->typing){
                this->typing=false;
            }
        }
    }
    if (event.type == sf::Event::TextEntered) { //if the keyboard keys are pressed to type
        if (this->typing) {
            if (event.text.unicode == 8) {
                if (playerInput.size() > 0) {
                    playerInput.erase(playerInput.size() - 1, 1); // erase the last character in the string
                    playerName.setString(playerInput);
                }
            } else { //if backspace is not pressed, write
                if(playerInput.size()<17) {
                    playerInput += event.text.unicode;
                    playerName.setString(playerInput);
                }
            }
        }
    }
}





