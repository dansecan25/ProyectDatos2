//
// Created by dansecan on 11/03/23.
//

#include "../Headers/GameScreen.h"
#include "../Headers/Player.h"
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

GameScreen::GameScreen(sf::RenderWindow *window, LinkedListStructured *mapStructures, gameStateStack *states, int mode)
:WindowState(window, mapStructures,states){
    this->initKeybinds();
    if (mode == 1){
        number_of_enemies = 10;
    } else if (mode == 2){
        number_of_enemies = 15;
    } else if (mode == 3){
        number_of_enemies = 20;
    } else{
        cout<< "Error with number of enemies";
    }

    for(int i=0; i<=number_of_enemies; i++)
    {
        EnemyShip *enemy = new EnemyShip(i, 100);//alienMinSpeed + (rand()%alienMaxSpeed) );
        enemy->setLocation(i*100+50, enemy->getSprite().getGlobalBounds().height/2);
        enemyList->insertEnemy(enemy);
    }
    cout<<"Print the enemy list";
    enemyList->printList(enemyList->getHead());
    //EnemyManager enemy_manager;
    //enemy_manager.setLevel(mode);
}

GameScreen::~GameScreen() {

}

void GameScreen::endState() {
    cout<<"Goodbye suckers!"<<endl;
}

void GameScreen::updateInput(const float &dt) {
    this->checkForQuit();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Move_Up")))){
        this->player.move(dt, 0,-2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds->getNode("Move_Down")))){
        this->player.move(dt, 0,2);
    }
}
void GameScreen::stateUpdate(const float& dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);
    this->player.updateEntity(dt);

    sf::Time t = alienClock.getElapsedTime();

    if(t.asSeconds() > 0.5)
    {
        for(size_t i=0; i<7; i++)
        {
            enemyList->findEnemy(i)->getSprite().move(0.f,enemyList->findEnemy(i)->getSpeed()*deltaTime);
        }
        alienClock.restart();
    }

    /*
    for(int i=0; i<number_of_enemies; i++)
    {
        EnemyShip alien(i, alienMinSpeed + (rand()%alienMaxSpeed) );
        alien.setLocation(i*100+50, alien.getSprite().getGlobalBounds().height/2);
        enemyList[i].editNode(alien);
    }
    sf::Time t = alienClock.getElapsedTime();
    //cout<<t.asSeconds()<<endl;
    if(t.asSeconds() > 0.5)
    {
        for(size_t i=0; i<7; i++)
        {
            enemyList[i].getSprite().move(0.f,enemyList[i].getSpeed()*deltaTime);
        }
        alienClock.restart();
    }
    */

    //enemy_manager.update();
}

void GameScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->player.renderEntity(this->window);

    for(size_t i=0;i<number_of_enemies;i++)
    {
        if(enemyList->findEnemy(i)->isAlive())
        {
            enemyList->findEnemy(i)->draw(this->window);
        }
    }

    //enemy_manager.draw(this->window);
}

void GameScreen::initKeybinds() {
    this->keyBinds->insertNode("Move_Up",this->supportedKeys->getNode("W"));
    this->keyBinds->insertNode("Move_Down",this->supportedKeys->getNode("S"));
    this->keyBinds->insertNode("Quit",this->supportedKeys->getNode("Escape"));
}

