//
// Created by dansecan on 11/03/23.
//

#include "../Headers/MainScreen.h"

MainScreen::MainScreen() {
    this->states=new gameStateStack();
    this->supportedKeys=new LinkedListStructured();
//    this->supportedKeys->insertNode("Try1",99);
//    this->supportedKeys->insertNode("Try2",98);
//    cout<<this->supportedKeys->getNode("Try1")<<endl;
//    cout<<this->supportedKeys->getNode("Try2")<<endl;
    this->createWindow();
    this->initWindowState();
    this->initKeys();


//    this->gamestate_btn=new SfmlButton(100,100,150, 50, &sf::Font('Arial'), "Start Game",
//                                       sf::Color(70,70,70,200),
//                                       sf::Color(150,150,150,255),
//                                       sf::Color(20,20,20,200));


}
/**
 * @brief destructor for the class and releases the memory from the pointers
 */
MainScreen::~MainScreen() {
    //delete this->gamestate_btn;
    delete this->mainWindow;
    //need stack
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
void MainScreen::run() {
    while (this->mainWindow->isOpen()) //
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
void MainScreen::endApp() {
    std::cout <<"Ending app"<<"\n";
}
/**
 * @brief initializes the main screen window
 */
void MainScreen::createWindow() {
    this->mainWindow = new sf::RenderWindow(VideoMode(1000, 626), "Battle Space Project", sf::Style::Titlebar | sf::Style::Close);
    this->mainWindow->setFramerateLimit(60);
}
/**
 * @brief updates the timer of execution, show the time every time its called
 */
void MainScreen::updateDt() {
    this->dt=this->dtClock.restart().asSeconds();
}
/**
 * @brief updates the elements of the game window
 */
void MainScreen::update() {
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
void MainScreen::render() {
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
void MainScreen::updateEvents() {
    Event event{};
    while (this->mainWindow->pollEvent(event))
    {
        if (event.type == Event::Closed)
            this->mainWindow->close();
    }
}
/**
 * @brief pushes a GameScreen object into the stack
 */
void MainScreen::initWindowState() {
    this->states->push(new GameScreen(this->mainWindow));

}

void MainScreen::initKeys() {
    this->supportedKeys->insertNode("W",sf::Keyboard::Key::W);
    this->supportedKeys->insertNode("S",sf::Keyboard::Key::S);
    cout<<this->supportedKeys->getNode("W")<<endl;

}



