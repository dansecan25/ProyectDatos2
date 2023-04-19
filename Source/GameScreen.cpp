//
// Created by dansecan on 11/03/23.
//

#include "../Headers/GameScreen.h"
#include "../Headers/GameOverScreen.h"
#include <iostream>
#include <list>
#include <csignal>
#include <thread>

using namespace std;

/**
 * @brief gamesScreen state constructor
 * @param window RenderWindow pointer
 * @param mapStructures LinkedListStructured pointer
 * @param states gameStatesStack pointer
 * @param mode int
 */
GameScreen::GameScreen(sf::RenderWindow* window, LinkedListStructured* mapStructures, WindowStatesStack* states, int mode)
:WindowState(window, mapStructures,states){
    this->initVariables();
    this->initObjects();
    this->initKeybinds();
    this->initTextures();
    this->initPlayer();

    this->mode = mode;
    makePattern(mode);
    createEnemyList(wave);

    bulletClock.restart().asSeconds();
    enemyClock.restart().asSeconds();
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
        delete enemyList;
        EnemyList *enemyList = new EnemyList();
        wave = wave + 1;
        createEnemyList(wave);
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

    if (enemyList->lenEnemyList(enemyList->getHead()) == NULL && wave <= 5){
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

    if (mode == 3){
        for(size_t i=0;i<(level_sketch.length())-3;i++) {
            if(enemyList->findEnemy(i)->isAlive()) {
                enemyList->findEnemy(i)->draw(this->window);
            }
        }
    } else {
        for(size_t i=0;i<(level_sketch.length())-2;i++) {
            if(enemyList->findEnemy(i)->isAlive()) {
                enemyList->findEnemy(i)->draw(this->window);
            }
        }
    }
    //enemy's movement
    sf::Time ec = enemyClock.getElapsedTime();
    std::srand(std::time(nullptr));
    sf::Vector2<float> pos = player->getPosition();

    if(ec.asSeconds() > speed)
    {
        int num_rand = (std::rand() % enemyList->lenEnemyList(enemyList->getHead()));
        enemyList->findEnemy(num_rand)->getSprite().move(-50,0);
        enemyClock.restart();

        if (enemyList->findEnemy(num_rand)->getSprite().getPosition().x <= pos.x){
            GameOver();
        }
    }
    //Bullets shooting
    sf::Vector2u windowsize = window->getSize();
    sf::Time bc = bulletClock.getElapsedTime();

    sf::Vector2f bulletV = bulletOriginal->getHead()->getPosition();
/*
    while(bulletOriginal->getHead()->getPosition().x <= windowsize.x ){

        if(bc.asSeconds() > 1.0) {
            sf::Vector2f bulletV = bulletOriginal->getHead()->getPosition();
            cout<<"\npos"<<bulletV.x<<"and"<<bulletV.y;

            bulletOriginal->getHead()->getSprite().move(+0.01,0);
            bulletOriginal->getHead()->draw(window);

            bulletClock.restart();
        }
    }*/
    //Shooting bullets
    bulletOriginal->getHead()->setPosition(pos.x,pos.y);

    if (bulletClock.getElapsedTime().asSeconds() >= 3.0f){
        while (bulletOriginal->getHead()->getPosition().x <= windowsize.x){
            cout<<"disparar";
            bulletOriginal->getHead()->getSprite().move(+10,0);
            bulletOriginal->getHead()->draw(this->window);
            cout<<"\npos"<<bulletV.x<<"and"<<bulletV.y;
        }
        bulletClock.restart();}
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
                ypos = 0;
                xpos = xpos + 50;
                break;
            }
            case '0': {
                EnemyShip *enemy = new EnemyShip(i, sketch_character, resistance);
                enemy->setLocation(xpos, ypos*100+50);
                enemyList->insertEnemy(enemy);
                i++;
                ypos++;
                break;
            }
            case '1': {
                EnemyShip *enemy = new EnemyShip(i, sketch_character,resistance + 10);
                enemy->setLocation(xpos, ypos*100+50);
                enemyList->insertEnemy(enemy);
                i++;
                ypos++;
                break;
            }
            case '2': {
                EnemyShip *enemy = new EnemyShip(i, sketch_character, resistance + 25);
                enemy->setLocation(xpos, ypos*100+50);
                enemyList->insertEnemy(enemy);
                i++;
                ypos++;
                break;
            }
        }}
    cout<<"Print the enemy list\n";
    enemyList->printList(enemyList->getHead());

    //Create bullet list
    this->bulletBackup = bulletNum;
    for (int i = 0; i <= bulletBackup; i++){
        bulletOriginal->addBullet(i, 50);
    }
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
 */
void GameScreen::makePattern(int n){ //pattern for showing enemies
    //Reference for enemy patterns https://github.com/Kofybrek/Space-invaders.git
    switch (n){
        case 1: {
            this->bulletNum = 10;
            this->resistance = 20;
            this->speed = 3.0;

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
            this->bulletNum = 150;
            this->resistance = 35;
            this->speed = 2.0;

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
            this->bulletNum = 200;
            this->resistance = 50;
            this->speed = 1.0;

            EnemyShip *pattern1 = new EnemyShip(1);
            pattern1->setPattern("101010\n101010\n110011\n212121");
            patternArray->insertEnemy(pattern1);

            EnemyShip *pattern2 = new EnemyShip(2);
            pattern2->setPattern("101010\n011110\n111111\n212121");
            patternArray->insertEnemy(pattern2);

            EnemyShip *pattern3 = new EnemyShip(3);
            pattern3->setPattern("111111\n121212\n212121\n211112");
            patternArray->insertEnemy(pattern3);

            EnemyShip *pattern4 = new EnemyShip(4);
            pattern4->setPattern("111111\n122221\n222222\n222222");
            patternArray->insertEnemy(pattern4);

            EnemyShip *pattern5 = new EnemyShip(5);
            pattern5->setPattern("121212\n222222\n222222");
            patternArray->insertEnemy(pattern5);

            break;
        }
    }
}
void GameScreen::GameOver(){
    this->states->push(new GameOverScreen(this->window, this->supportedKeys, this->states));

}