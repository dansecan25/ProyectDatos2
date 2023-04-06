//
// Created by dansecan on 11/03/23.
//

#include "../Headers/ApplicationManager.h"

ApplicationManager::ApplicationManager() {
    this->states=new gameStateStack();
    this->supportedKeys=new LinkedListStructured();

    this->createWindow();
    this->initKeys();
    this->initWindowState();


}
/**
 * @brief destructor for the class and releases the memory from the pointers
 */
ApplicationManager::~ApplicationManager() {
    delete this->mainWindow;
    while(!this->states->isEmpty())
        this->states->pop(); //will go through every element from the stack and delete every one of them
    delete this->states;
    while(this->supportedKeys->getLen()>0){
        this->supportedKeys->deleteLast();
    }
    delete this->supportedKeys;
}
/**
 * @brief runs the window and executes the refresing of the screen
 */
void ApplicationManager::run() {
    while (this->mainWindow->isOpen()) //
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
void ApplicationManager::endApp() {
    std::cout <<"Closing"<<"\n";
}
/**
 * @brief initializes the main screen window
 */
void ApplicationManager::createWindow() {
    this->mainWindow = new sf::RenderWindow(VideoMode(1000, 626), "Battle Space Project", sf::Style::Titlebar | sf::Style::Close);
    this->mainWindow->setFramerateLimit(60);
}
/**
 * @brief updates the timer of execution, show the time every time its called
 */
void ApplicationManager::updateDt() {
    this->dt=this->dtClock.restart().asSeconds();
}
/**
 * @brief updates the elements of the game window
 */
void ApplicationManager::update() {
    this->updateEvents();

    if(!this->states->isEmpty()){
        this->states->peek()->stateUpdate(this->dt); //peeks the top element of the stack
        if(this->states->peek()->getQuit()){
            //here goes something if the game is quitted, if return to mainscren
            this->states->peek()->endState();
            this->states->pop(); //pop instantly frees the memory stored in the current top
        }
    }else{
        this->endApp();
        this->mainWindow->close(); //ends the app
    }
}
/**
 * @brief renders the images and objects into the window
 */
void ApplicationManager::render() {
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("../Resources/Images/SpaceBackground.jpg");
    sf::Sprite backgroundSprite(backgroundTexture);

    this->mainWindow->clear();
    this->mainWindow->draw(backgroundSprite);
    if(!this->states->isEmpty()){ //checks if the stack is not empty
        this->states->peek()->stateRender(this->mainWindow);
    }

    this->mainWindow->display();
}
/**
 * @brief updates the events on the game
 */
void ApplicationManager::updateEvents() {
    Event event{};
    while (this->mainWindow->pollEvent(event))
    {
        if (event.type == Event::Closed)
            this->mainWindow->close();
    }
}
/**
 * @brief pushes a WindowState object into the stack
 */
void ApplicationManager::initWindowState() {
    this->states->push(new MainScreen(this->mainWindow, this->supportedKeys,this->states));

}
/**
 * @brief stores the keys that are supported
 */
void ApplicationManager::initKeys() {
    this->supportedKeys->insertNode("Escape",sf::Keyboard::Key::Escape);
    this->supportedKeys->insertNode("W",sf::Keyboard::Key::W);
    this->supportedKeys->insertNode("S",sf::Keyboard::Key::S);
}



