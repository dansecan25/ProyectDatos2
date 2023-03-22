#include <iostream>
#include "Headers/MainScreen.h"
int main() {
    MainScreen screen = MainScreen();
    return 0;
}
//g++ main.cpp -o projectBattleSpace.exe -lsfml-graphics -lsfml-window -lsfml-system
//./projectBatlleSpace.exe
// in case of break, edit cmake in line 7 adding the sfml libraries