//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_GAMESCREEN_H
#define PROYECTDATOS2_GAMESCREEN_H
#include "../Headers/WindowState.h"
#include "SfmlButton.h"
#include "EnemyManager.h"
#include "../Source/EnemyList.h"
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

using namespace std;
class GameScreen
        : public WindowState{
private:
    Entities player;
    //EnemyManager enemy_manager;

    const int alienMaxSpeed = 1200;
    const int alienMinSpeed = 500;
    //clock for aliens
    sf::Clock alienClock;
    //alienClock.restart().asSeconds();
    sf::Clock clock;
    float deltaTime = clock.restart().asSeconds();
    //EnemyShip alienArray[NUMBER_OF_ALIENS];

    int number_of_enemies;
    string level_sketch;
    int mode;
    EnemyList *enemyList = new EnemyList();

    void initKeybinds() override;
public:
    explicit GameScreen(sf::RenderWindow *window, LinkedListStructured *mapStructures, gameStateStack *states, int i);
    ~GameScreen() override;
    void endState()override;
    void updateInput(const float& dt) override;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;
};


#endif //PROYECTDATOS2_GAMESCREEN_H
