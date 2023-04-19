//
// Created by dansecan on 18/04/23.
//

#ifndef PROYECTDATOS2_POWERLOADED_H
#define PROYECTDATOS2_POWERLOADED_H
#include <iostream>

class PowerLoaded {
private:

    int cooldown;
    float cost;

public:
    std::string name;
    PowerLoaded(std::string name, int cooldown, int cost);
    int getCooldown();
    int getCost();
    std::string getName();

};


#endif //PROYECTDATOS2_POWERLOADED_H
