//
// Created by monicaegm on 4/6/23.
//

#include "../Headers/EnemyManager.h"
#include "../Headers/EnemyShip.h"
#include <SFML/Graphics.hpp>
#include <random>

EnemyManager::EnemyManager(){

}
/*
void EnemyManager::draw(sf::RenderTarget * target) {

    for (EnemyShip &enemy: enemies) {
        target.draw(enemy_sprite);
        sf::Color enemy_color = sf::Color(255, 255, 255);

        if (0 == enemy.get_hit_timer()) //If enemy not hit then colour it
        {
            switch (enemy.get_type()) {
                case 0: {
                    enemy_color = sf::Color(0, 255, 255);
                    break;
                }
                case 1: {
                    enemy_color = sf::Color(255, 0, 255);
                    break;
                }
                case 2: {
                    enemy_color = sf::Color(0, 255, 0);
                }
            }
        }
    }
}
void EnemyManager::setLevel(int mode){
    std::string level_sketch = "";
    unsigned char enemy_x = 0;
    unsigned char enemy_y = 0;

    switch (mode) {
        case 1: {
            level_sketch = "0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0";
            break;
        }
        case 2: {
            level_sketch = "1010101010101010\n0101010101010101\n1010101010101010\n0101010101010101";
            break;
        }
        case 3: {
            level_sketch = "1111111111111111\n1111111111111111\n1111111111111111\n1111111111111111";
            break;

        }
    }
    for (char sketch_character : level_sketch) {
        enemy_x++;

        switch (sketch_character) {
            case '\n': {
                enemy_x = 0;
                enemy_y++;

                break;
            }
            case '0': {
                enemies.push_back(EnemyShip(0, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y)));

                break;
            }
            case '1': {
                enemies.push_back(EnemyShip(1, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y)));

                break;
            }
            case '2': {
                enemies.push_back(EnemyShip(2, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y)));
            }
        }
}}

void EnemyManager::update(){
    //std::vector<EnemyShip>::iterator dead_enemies_start;
    if (0 == move_timer) {
        move_timer = move_pause;

        for (EnemyShip& enemy : enemies) {
            enemy.move();
        }
    } else {
        move_timer--;
    }
}
*/