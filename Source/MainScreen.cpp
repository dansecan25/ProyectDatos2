//
// Created by dansecan on 06/04/23.
//

#include "../Headers/MainScreen.h"

MainScreen::MainScreen(sf::RenderWindow* window, LinkedListStructured* supportedKeys,gameStateStack* states)
: WindowState(window,supportedKeys,states){
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

}

MainScreen::~MainScreen() {
    delete this->startButton;
    delete this->exitButton;
}

void MainScreen::endState() {
    cout<<"Ending app"<<endl;
}
/**
 * @brief updates the event keys pressed actions when input happens
 * @param dt int time
 */
void MainScreen::updateInput(const float &dt) {
    this->checkForQuit();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){

    }
}
void MainScreen::initKeybinds() {
    this->keyBinds->insertNode("Move_Up",this->supportedKeys->getNode("W"));
    this->keyBinds->insertNode("Move_Down",this->supportedKeys->getNode("S"));
    this->keyBinds->insertNode("Quit",this->supportedKeys->getNode("Escape"));
}

void MainScreen::stateUpdate(const float &dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);

    this->updateButtons();

}

void MainScreen::stateRender(sf::RenderTarget *target) {
    if(!target){
        target=this->window;
    }
    this->renderButtons(target);
}
/**
 * @brief loads the font to the font attribute
 */
void MainScreen::initFonts() {
    if (!this->font.loadFromFile("../Resources/Fonts/arial.ttf"))
    {
        exit(200);
    }

}

void MainScreen::initButtons() {
    this->startButton=new SfmlButton(450, 400, 200, 75, &font, "Start Game",
                                     sf::Color(70,70,70,200),
                                     sf::Color(150,150,150,255),
                                     sf::Color(20,20,20,200));
    this->exitButton=new SfmlButton(50, 50, 75, 40, &font, "Exit",
                                     sf::Color(70,70,70,200),
                                     sf::Color(150,150,150,255),
                                     sf::Color(20,20,20,200));

}

void MainScreen::updateButtons() {
    this->startButton->update(this->positions.posXf, this->positions.posYf);
    //here goes when start button is pressed
    if(this->startButton->isPressed()){
        this->states->push(new GameScreen(this->window,this->supportedKeys,this->states));
    }
    this->exitButton->update(this->positions.posXf, this->positions.posYf);
    if(this->exitButton->isPressed()){
        this->quit=true;
    }



}

void MainScreen::renderButtons(sf::RenderTarget *target) {
    this->startButton->render(target);
    this->exitButton->render(target);




}
