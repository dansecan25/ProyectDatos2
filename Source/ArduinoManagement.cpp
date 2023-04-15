//
// Created by dansecan on 14/04/23.
//

#include "Headers/ArduinoManagement.h"

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

std::string ArduinoManagement::getJoystickMovement() {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    mySerial.flushInput();
    std::string response = mySerial.read(6);
    if(response.length()>0){
        std::cout <<"Arduino says: "<<response<<std::endl;
    }
    return response;
}

int ArduinoManagement::getPotentiometerValue() {
    return 0;
}

void ArduinoManagement::sendWave(int wave) {
    //send a string to arduino
//       std::string tests_string = "hi\n";
//       for(int i=0;i<3;i++){
//           size_t bytesWritten = mySerial.write(tests_string);
//           std::cout<<"bytes sent"<<bytesWritten<<std::endl;
//           std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//       }
}

void ArduinoManagement::sendPass(std::string passed) {

}

void ArduinoManagement::sendWindowState(std::string state) {

}

