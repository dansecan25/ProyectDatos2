//
// Created by dansecan on 11/03/23.
//

#include "../Headers/MainScreen.h"

MainScreen::MainScreen() {
    this->createWindow();
    this->initWindowState();
    this->mainWindow->setFramerateLimit(60);
//    this->gamestate_btn=new SfmlButton(100,100,150, 50, &sf::Font('Arial'), "Start Game",
//                                       sf::Color(70,70,70,200),
//                                       sf::Color(150,150,150,255),
//                                       sf::Color(20,20,20,200));


}
/**
 * @brief destructor for the class and releases the memory from the pointers
 */
MainScreen::~MainScreen() {
    delete this->gamestate_btn;
    delete this->mainWindow;
    //need stack
//    while(!this->states.empty())
//        delete this->states.top();
//         this.pop()
}
/**
 * @brief initializes the main screen window
 */
void MainScreen::createWindow() {
    this->mainWindow = new sf::RenderWindow(VideoMode(1000, 626), "Battle Space Project", sf::Style::Titlebar | sf::Style::Close);
}


void MainScreen::update() {
    this->updateEvents();
    //uncomment when stack is created
//    if(this->states.empty()){
//        this->states.top()->update(this->dt);
//    }
}

void MainScreen::render() {
    sf::Texture t;
    //t=ImageLoader::getInstance()->getTexture("../Resources/images/SpaceBackground.jpg");
    t.loadFromFile("../Resources/Images/SpaceBackground.jpg");
    sf::Sprite s(t);
    this->mainWindow->clear();
    //uncomment when stack is created
//    if(this->states.empty()){
//        this->states.top()->render(this->mainWindow);
//    }


    this->mainWindow->draw(s);
    this->mainWindow->display();
}

void MainScreen::updateEvents() {
    Event event{};
    while (this->mainWindow->pollEvent(event))
    {
        if (event.type == Event::Closed)
            this->mainWindow->close();
    }
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

void MainScreen::updateDt() {
    this->dt=this->dtClock.restart().asSeconds();

    system("cls");
    cout<<this->dt<<"\n";
}

void MainScreen::initWindowState() {
    //this->states.push(new WindowState(this->mainWindow)); //this will add the state object to the stack
}

