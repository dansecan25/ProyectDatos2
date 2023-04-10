//
// Created by dansecan on 11/03/23.
//

#include "../Headers/GameScreen.h"
#include <iostream>
#include <list>

GameScreen::GameScreen(sf::RenderWindow *window, LinkedListStructured *mapStructures, gameStateStack *states, int mode)
:WindowState(window, mapStructures,states){
    this->initKeybinds();

    this->mode = mode;

    if (mode == 1){
        number_of_enemies = 15;
    } else if (mode == 2){
        number_of_enemies = 15;
    } else if (mode == 3){
        number_of_enemies = 20;
    } else{
        cout<< "Error with number of enemies \n";
    }

    EnemyShip *pattern = new EnemyShip();
    this->level_sketch = pattern->makePattern(mode);
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
                EnemyShip *enemy = new EnemyShip(i, 100, sketch_character);//alienMinSpeed + (rand()%alienMaxSpeed) );
                enemy->setLocation(xpos, ypos*100+50);//enemy->getSprite().getGlobalBounds().height/2
                enemyList->insertEnemy(enemy);
                i++;
                ypos++;
                break;
            }
            case '1': {
                EnemyShip *enemy = new EnemyShip(i, 100, sketch_character);//alienMinSpeed + (rand()%alienMaxSpeed) );
                enemy->setLocation(xpos, ypos*100+50);//enemy->getSprite().getGlobalBounds().height/2
                enemyList->insertEnemy(enemy);
                i++;
                ypos++;
                break;
            }
            case '2': {
                EnemyShip *enemy = new EnemyShip(i, 100, sketch_character);//alienMinSpeed + (rand()%alienMaxSpeed) );
                enemy->setLocation(xpos, ypos*100+50);//enemy->getSprite().getGlobalBounds().height/2
                enemyList->insertEnemy(enemy);
                i++;
                ypos++;
                break;
            }
    }}

    /*
    for(int i=0; i<number_of_enemies; i++)
    {
        EnemyShip *enemy = new EnemyShip(i, 100, mode);//alienMinSpeed + (rand()%alienMaxSpeed) );
        enemy->setLocation(enemy->getSprite().getGlobalBounds().height/2, i*100+50);
        enemyList->insertEnemy(enemy);
    }
     */
    cout<<"Print the enemy list\n";
    enemyList->printList(enemyList->getHead());
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
    /*
    sf::Time t = alienClock.getElapsedTime();

    if(t.asSeconds() > 0.5)
    {
        for(size_t i=0; i<7; i++)
        {
            enemyList->findEnemy(i)->getSprite().move(0.f,enemyList->findEnemy(i)->getSpeed()*deltaTime);
        }
        alienClock.restart();
    }*/
}

void GameScreen::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->player.renderEntity(this->window);

    for(size_t i=0;i<(level_sketch.length())-2;i++) {
        if(enemyList->findEnemy(i)->isAlive()) {
            enemyList->findEnemy(i)->draw(this->window);
        }
    }
}

void GameScreen::initKeybinds() {
    this->keyBinds->insertNode("Move_Up",this->supportedKeys->getNode("W"));
    this->keyBinds->insertNode("Move_Down",this->supportedKeys->getNode("S"));
    this->keyBinds->insertNode("Quit",this->supportedKeys->getNode("Escape"));
}

