//
// Created by dansecan on 14/04/23.
//

#include "Headers/ArduinoManagement.h"
/**
 * @brief constructor of mySerial and ArduinoManagement, checks if the port was opened or not
 */
ArduinoManagement::ArduinoManagement() : mySerial(port, baudRate, serial::Timeout::simpleTimeout(3000)){
    if(mySerial.isOpen()){
        std::cout <<"Port opened succesfully"<<std::endl;
    }else{
        std::cout <<"Port not opened"<<std::endl;
        exit(2000);
    }
    mySerial.flushOutput(); //clears the buffer
}

bool ArduinoManagement::connectedArduino() {
    return false;
}
/**
 * @brief gets the string the joystick sends
 * @return string
 */
std::string ArduinoManagement::getJoystickMovement() {
    if (mySerial.available()) {
        std::string response = mySerial.read(6);
        if (response.length() > 0) {
            return response;
        }
    }
    // Return "none" if no data was read
    return "none";

}
/**
 * @brief gets the value of the potentiometer
 * @return
 */
int ArduinoManagement::getPotentiometerValue() {
    int value=-1;
    if (mySerial.available()) {
        std::string response = mySerial.read(6);
        if (response.length() > 0) {
            try{
                value=std::stoi(response);
            }catch(const std::invalid_argument& e){
                value=0;
            }
        }
    }
    // Return "none" if no data was read
    return value;
}

void ArduinoManagement::sendWave(int wave) {
    // Convert wave number to string
    std::string waveString = std::to_string(wave) + "\n";

    // Send string to Arduino
    size_t bytesWritten = mySerial.write(waveString.c_str());
}
/**
 * @brief send if enemy passed the x value
 * @param passed string
 */
void ArduinoManagement::sendPass(std::string passed) {
    // Send string to Arduino
    size_t bytesWritten = mySerial.write(passed.c_str());
}
/**
 * @brief sends the state of the window
 * @param state
 */
void ArduinoManagement::sendWindowState(std::string state) {
    // Send string to Arduino
    size_t bytesWritten = mySerial.write(state.c_str());
}

