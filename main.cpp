#include <iostream>
#include "Headers/ApplicationManager.h"
int main() {
    ApplicationManager gameCreate;
    gameCreate.run();
    return 0;
}
//g++ main.cpp -o projectBattleSpace.exe -lsfml-graphics -lsfml-window -lsfml-system
//./projectBatlleSpace.exe
// in case of break, edit cmake in line 7 adding the sfml libraries