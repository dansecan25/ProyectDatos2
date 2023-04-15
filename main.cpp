#include <iostream>
#include "Headers/ApplicationManager.h"
#include "Source/arduinoConnectionTest.cpp"
int main() {
    ApplicationManager app;
    app.run();
}
//g++ main.cpp -o projectBattleSpace.exe -lsfml-graphics -lsfml-window -lsfml-system
//./projectBatlleSpace.exe
// in case of break, edit cmake in line 7 adding the sfml libraries