//
// Created by dansecan on 14/04/23.
//

#ifndef PROYECTDATOS2_ARDUINOMANAGEMENT_H
#define PROYECTDATOS2_ARDUINOMANAGEMENT_H
#include <iostream>
#include "../ThirdPartyFolder/include/serial/serial.h"
#include "thread"

class ArduinoManagement {
public:

    ArduinoManagement();
    bool connectedArduino();
    std::string getJoystickMovement();
    int getPotentiometerValue();
    void sendWindowState(std::string state);
    void sendWave(int wave);
    void sendPass(std::string passed);
private:
    std::string port = "/dev/ttyACM0";
    int baudRate=3600;
    serial::Serial mySerial;

};


#endif //PROYECTDATOS2_ARDUINOMANAGEMENT_H
