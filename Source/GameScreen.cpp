//
// Created by dansecan on 11/03/23.
//

#include "../Headers/GameScreen.h"
#include <iostream>
#include <list>

/**
 * @brief gamesScreen state constructor
 * @param window RenderWindow pointer
 * @param mapStructures LinkedListStructured pointer
 * @param states gameStatesStack pointer
 * @param mode int
 */
GameScreen::GameScreen(sf::RenderWindow* window, LinkedListStructured* mapStructures, WindowStatesStack* states, int mode, ArduinoManagement* arduino)
:WindowState(window, mapStructures,states, arduino){
    this->initVariables();
    this->initObjects();
    this->initKeybinds();
    this->initTextures();
    this->initPlayer();

    this->mode = mode;
    makePattern(mode);
    createEnemyList(wave);
}
/**
 * @brief constructor to state GameScreen
 */
GameScreen::~GameScreen() {
    delete player;
}
/**
 * @brief updates the inputs events on the current state of the window
 * @param dt const float reference
 */
void GameScreen::updateInput(const float &dt) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Move_Up")))){
        this->player->move(dt, 0,-2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Move_Down")))){
        this->player->move(dt, 0,2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("kill_all")))){
        cout<<"killing enemies";
        for (EnemyShip* enemy = enemyList->getHead();enemy != nullptr; enemy = enemy->getNext())
        {
            enemyList->deleteEnemy(enemy->getId());
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Quit")))){
        this->endState();
    }
}
/**
 * @brief updates the events in the window
 * @param dt const float reference
 */
void GameScreen::stateUpdate(const float& dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);
    this->player->updateEntity(dt);

    if (enemyList->lenEnemyList(enemyList->getHead()) == 0 && wave <= 5){
        this->wave = wave+1;
        createEnemyList(wave);
    }
}
/**
 * @brief states what will be drawn in the window
 * @param target RenderTarget pointer
 */
void GameScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->player->renderEntity(target);

    for(size_t i=0;i<(level_sketch.length())-2;i++) {
        if(enemyList->findEnemy(i)->isAlive()) {
            enemyList->findEnemy(i)->draw(this->window);
        }
    }
}
/**
 * @brief stores the accepted keys in the linked list
 */
void GameScreen::initKeybinds() {
    this->keyBinds->insertNode("Move_Up",this->supportedKeys->getNode("W"));
    this->keyBinds->insertNode("Move_Down",this->supportedKeys->getNode("S"));
    this->keyBinds->insertNode("Quit",this->supportedKeys->getNode("Escape"));

    this->keyBinds->insertNode("kill_all",this->supportedKeys->getNode("K"));

}
/**
 * @brief Creates a list with enemies and their data
 * @param s int
 */
void GameScreen::createEnemyList(int s){
    this->level_sketch = patternArray->findEnemy(s)->getPattern();
    int i = 0;
    int xpos = 750;
    int ypos = 0;
    for (char sketch_character : level_sketch) {
        switch (sketch_character) {
            case '\n': {
                cout<<"no pattern";
                ypos = 0;
                xpos = xpos + 50;
                break;
            }
            case '0': {
                EnemyShip *enemy = new EnemyShip(i, 100, sketch_character);
                enemy->setLocation(xpos, ypos*100+50);
                enemyList->insertEnemy(enemy);
                i++;
                ypos++;
                break;
            }
            case '1': {
                EnemyShip *enemy = new EnemyShip(i, 100, sketch_character);
                enemy->setLocation(xpos, ypos*100+50);
                enemyList->insertEnemy(enemy);
                i++;
                ypos++;
                break;
            }
            case '2': {
                EnemyShip *enemy = new EnemyShip(i, 100, sketch_character);
                enemy->setLocation(xpos, ypos*100+50);
                enemyList->insertEnemy(enemy);
                i++;
                ypos++;
                break;
            }
        }}
    cout<<"Print the enemy list\n";
    enemyList->printList(enemyList->getHead());
}
/**
 * @brief init the background objects, GUI
 */
void GameScreen::initObjects() {
    //this->backGround.setSize(sf::Vector2f(static_cast<float>(1000),static_cast<float>(60)));
    //this->backGroundTexture.loadFromFile("../Resources/Images/GUI.jpg");
    //this->backGround.setTexture(backGroundTexture);

}
/**
 * @brief inits the variables
 */
void GameScreen::initVariables() {


}
/**
 * @brief inits the textures
 */
void GameScreen::initTextures() {
    this->textures->insertNode("PlayerTexture","../Resources/Images/SpaceShipPlayer.png");
}
/**
 * @brief inits the player
 */
void GameScreen::initPlayer() {
    std::string route=this->textures->getNode("PlayerTexture");
    this->player=new Player(50, 310,route);
}

/**
 * @brief Sets the pattern of enemies to be drawn
 * @param n int
 * @return level_sketch char
 */
void GameScreen::makePattern(int n){ //pattern for showing enemies
    //Reference for enemy patterns https://github.com/Kofybrek/Space-invaders.git
    switch (n){
        case 1: {
            EnemyShip *pattern1 = new EnemyShip(1);
            pattern1->setPattern("000000\n000000\n000000");
            patternArray->insertEnemy(pattern1);

            EnemyShip *pattern2 = new EnemyShip(2);
            pattern2->setPattern("000000\n000000\n101010");
            patternArray->insertEnemy(pattern2);

            EnemyShip *pattern3 = new EnemyShip(3);
            pattern3->setPattern("000000\n101010\n101010");
            patternArray->insertEnemy(pattern3);

            EnemyShip *pattern4 = new EnemyShip(4);
            pattern4->setPattern("000000\n101010\n111111");
            patternArray->insertEnemy(pattern4);

            EnemyShip *pattern5 = new EnemyShip(5);
            pattern5->setPattern("101010\n110011\n111111");
            patternArray->insertEnemy(pattern5);

            break;
        }
        case 2: {
            EnemyShip *pattern1 = new EnemyShip(1);
            pattern1->setPattern("001100\n000000\n101010");
            patternArray->insertEnemy(pattern1);

            EnemyShip *pattern2 = new EnemyShip(2);
            pattern2->setPattern("001100\n101010\n111111");
            patternArray->insertEnemy(pattern2);

            EnemyShip *pattern3 = new EnemyShip(3);
            pattern3->setPattern("101010\n101010\n111111");
            patternArray->insertEnemy(pattern3);

            EnemyShip *pattern4 = new EnemyShip(4);
            pattern4->setPattern("101010\n011110\n121212");
            patternArray->insertEnemy(pattern4);

            EnemyShip *pattern5 = new EnemyShip(5);
            pattern5->setPattern("101010\n122221\n222222");
            patternArray->insertEnemy(pattern5);

            break;
        }
        case 3: {
            EnemyShip *pattern1 = new EnemyShip(1);
            pattern1->setPattern("101010\n101010\n212121");
            patternArray->insertEnemy(pattern1);

            EnemyShip *pattern2 = new EnemyShip(2);
            pattern2->setPattern("101010\n111111\n212121");
            patternArray->insertEnemy(pattern2);

            EnemyShip *pattern3 = new EnemyShip(3);
            pattern3->setPattern("111111\n121212\n211112");
            patternArray->insertEnemy(pattern3);

            EnemyShip *pattern4 = new EnemyShip(4);
            pattern4->setPattern("111111\n122221\n222222");
            patternArray->insertEnemy(pattern4);

            EnemyShip *pattern5 = new EnemyShip(5);
            pattern5->setPattern("121212\n222222\n222222");
            patternArray->insertEnemy(pattern5);

            break;
        }
    }
}