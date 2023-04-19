//
// Created by dansecan on 11/03/23.
//

#ifndef PROYECTDATOS2_STRATEGIES_H
#define PROYECTDATOS2_STRATEGIES_H
#include <iostream>
#include "../Headers/PowerLoaded.h"
#include "../ThirdPartyFolder/rapidxml-1.13/rapidxml.hpp"
#include "../ThirdPartyFolder/rapidxml-1.13/rapidxml_utils.hpp"
class Strategies {
public:
    Strategies();
    ~Strategies();
    void loadPower1(int power);
    void loadPower2(int power);
    void checkIfLoaded(std::string powerName);
private:
    std::string route1;
    std::string route2;
    std::string route3;
    std::string route4;
    PowerLoaded* loaded1;
    PowerLoaded* loaded2;
};


#endif //PROYECTDATOS2_STRATEGIES_H
