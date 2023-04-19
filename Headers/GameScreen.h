//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_GAMESCREEN_H
#define PROYECTDATOS2_GAMESCREEN_H
#include "../Headers/WindowState.h"
#include "SfmlButton.h"
#include "EnemyList.h"
#include "BulletCollector.h"
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include "../Headers/Strategies.h"

using namespace std;
class GameScreen
        : public WindowState{
private:
    Player *player;
    sf::RectangleShape backGround;
    sf::Texture backGroundTexture;
    void initObjects();
    void initVariables();
    void initKeybinds() override;
    Strategies* strategyManager;
    void makePattern(int);

    EnemyList *enemyList = new EnemyList();
    EnemyList *patternArray = new EnemyList();
    BulletCollector *bulletOriginal = new BulletCollector();
    void createEnemyList(int s);

    string level_sketch;
    int mode;
    int wave = 1;
    int bulletNum;
    int bulletBackup;
    int resistance;
    int speed;

    sf::Clock clock;
    sf::Clock bulletClock;
    sf::Clock enemyClock;
    sf::Clock bulletClock2;


    void initTextures();
    void initPlayer();
public:
    explicit GameScreen(sf::RenderWindow * window, LinkedListStructured* mapStructures, WindowStatesStack* states, int mode, ArduinoManagement* arduino, Strategies* strategies);
    ~GameScreen() override;
    void updateInput(const float& dt) override;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;

    void GameOver();
};


#endif //PROYECTDATOS2_GAMESCREEN_H
