//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_GAMESCREEN_H
#define PROYECTDATOS2_GAMESCREEN_H
#include "../Headers/WindowState.h"
#include "SfmlButton.h"
#include "EnemyManager.h"
#include "EnemyList.h"
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

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

    void makePattern(int);

    EnemyList *enemyList = new EnemyList();
    EnemyList *patternArray = new EnemyList();
    void createEnemyList(int s);

    string level_sketch;
    int mode;
    int wave = 1;
    int state;

    void initTextures();
    void initPlayer();
public:
    explicit GameScreen(sf::RenderWindow * window, LinkedListStructured* mapStructures, WindowStatesStack* states, int mode);
    ~GameScreen() override;
    void updateInput(const float& dt) override;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;









};


#endif //PROYECTDATOS2_GAMESCREEN_H
