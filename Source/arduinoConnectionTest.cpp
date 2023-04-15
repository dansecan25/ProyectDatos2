//
// Created by dansecan on 12/04/23.
//
#include <iostream>
#include "../ThirdPartyFolder/include/serial/serial.h"
#include "thread"



class SerialReceiver {
public:
    int receive(){
       serial::Serial mySerial("/dev/ttyACM0",9600, serial::Timeout::simpleTimeout(3000));
       if(mySerial.isOpen()){
           std::cout <<"Port opened succesfully"<<std::endl;
       }else{
           std::cout <<"Port not opened"<<std::endl;
           exit(2000);
       }
       mySerial.flushOutput(); //clears the buffer


        while(true){
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            mySerial.flushInput();
            std::string response = mySerial.read(6);
            if(response.length()>0){
                std::cout <<"Arduino says: "<<response<<std::endl;
            }

        }

    }

};

