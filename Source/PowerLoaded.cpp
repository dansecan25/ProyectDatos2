//
// Created by dansecan on 18/04/23.
//

#include "Headers/PowerLoaded.h"

PowerLoaded::PowerLoaded(std::string name, int cooldown, int cost) {
    this->name=name;
    this->cooldown=cooldown;
    this->cost=cost;
}

/**
 * @brief returns the cooldown
 * @return cooldown int
 */
int PowerLoaded::getCooldown() {
    return cooldown;
}
/**
 * @brief gets the power cost
 * @return
 */
int PowerLoaded::getCost() {
    return cost;
}

std::string PowerLoaded::getName() {
    return name;
}
