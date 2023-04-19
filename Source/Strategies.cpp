//
// Created by dansecan on 11/03/23.
//

#include "../Headers/Strategies.h"

Strategies::Strategies() {
    this->route1="../Strategies/StrategyOne.xml";
    this->route2="../Strategies/StrategyTwo.xml";
    this->route3="../Strategies/StrategyThree.xml";
    this->route4="../Strategies/StrategyFour.xml";
    this->loadPower1(1);
    this->loadPower2(2);
}

Strategies::~Strategies() {
    if(this->loaded1!= nullptr){
        delete this->loaded1;
    }
    if(this->loaded1!= nullptr){
        delete this->loaded2;
    }
}
/**
 * @brief loads power in page2
 * @param power int
 */
void Strategies::loadPower2(int power) {
    if(power==1){
        rapidxml::file<> xmlFile(route1.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        rapidxml::xml_node<>* root = doc.first_node();
        rapidxml::xml_node<>* timeNode = root->first_node("time");
        rapidxml::xml_node<>* nameNode = root->first_node("name");

        if (timeNode && nameNode) {
            std::string time(timeNode->value(), timeNode->value_size());
            std::string name(nameNode->value(), nameNode->value_size());
            int cooldown= stoi(time);
            this->loaded2=new PowerLoaded(name, cooldown, 30);
        }
    }else if(power==2){
        rapidxml::file<> xmlFile(route2.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        rapidxml::xml_node<>* root = doc.first_node();
        rapidxml::xml_node<>* timeNode = root->first_node("time");
        rapidxml::xml_node<>* nameNode = root->first_node("name");

        if (timeNode && nameNode) {
            std::string time(timeNode->value(), timeNode->value_size());
            std::string name(nameNode->value(), nameNode->value_size());
            int cooldown= stoi(time);
            this->loaded2=new PowerLoaded(name, cooldown, 30);
        }
    }else if(power==3){
        rapidxml::file<> xmlFile(route3.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        rapidxml::xml_node<>* root = doc.first_node();
        rapidxml::xml_node<>* timeNode = root->first_node("time");
        rapidxml::xml_node<>* nameNode = root->first_node("name");

        if (timeNode && nameNode) {
            std::string time(timeNode->value(), timeNode->value_size());
            std::string name(nameNode->value(), nameNode->value_size());
            int cooldown= stoi(time);
            this->loaded2=new PowerLoaded(name, cooldown, 30);
        }
    }else if(power==4){
        rapidxml::file<> xmlFile(route4.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        rapidxml::xml_node<>* root = doc.first_node();
        rapidxml::xml_node<>* timeNode = root->first_node("time");
        rapidxml::xml_node<>* nameNode = root->first_node("name");

        if (timeNode && nameNode) {
            std::string time(timeNode->value(), timeNode->value_size());
            std::string name(nameNode->value(), nameNode->value_size());
            int cooldown= stoi(time);
            this->loaded2=new PowerLoaded(name, cooldown, 30);
        }
    }
}
/**
 * @brief loads memory in page 1
 * @param power int
 */
void Strategies::loadPower1(int power) {

    if(power==1){
        rapidxml::file<> xmlFile(route1.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        rapidxml::xml_node<>* root = doc.first_node();
        rapidxml::xml_node<>* timeNode = root->first_node("time");
        rapidxml::xml_node<>* nameNode = root->first_node("name");

        if (timeNode && nameNode) {
            std::string time(timeNode->value(), timeNode->value_size());
            std::string name(nameNode->value(), nameNode->value_size());
            int cooldown= stoi(time);
            delete this->loaded1;
            this->loaded1=new PowerLoaded(name, cooldown, 30);
        }
    }else if(power==2){
        rapidxml::file<> xmlFile(route2.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        rapidxml::xml_node<>* root = doc.first_node();
        rapidxml::xml_node<>* timeNode = root->first_node("time");
        rapidxml::xml_node<>* nameNode = root->first_node("name");

        if (timeNode && nameNode) {
            std::string time(timeNode->value(), timeNode->value_size());
            std::string name(nameNode->value(), nameNode->value_size());
            int cooldown= stoi(time);
            delete this->loaded1;
            this->loaded1=new PowerLoaded(name, cooldown, 30);
        }
    }else if(power==3){
        rapidxml::file<> xmlFile(route3.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        rapidxml::xml_node<>* root = doc.first_node();
        rapidxml::xml_node<>* timeNode = root->first_node("time");
        rapidxml::xml_node<>* nameNode = root->first_node("name");

        if (timeNode && nameNode) {
            std::string time(timeNode->value(), timeNode->value_size());
            std::string name(nameNode->value(), nameNode->value_size());
            int cooldown= stoi(time);
            delete this->loaded1;
            this->loaded1=new PowerLoaded(name, cooldown, 30);
        }
    }else if(power==4){
        rapidxml::file<> xmlFile(route4.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        rapidxml::xml_node<>* root = doc.first_node();
        rapidxml::xml_node<>* timeNode = root->first_node("time");
        rapidxml::xml_node<>* nameNode = root->first_node("name");

        if (timeNode && nameNode) {
            std::string time(timeNode->value(), timeNode->value_size());
            std::string name(nameNode->value(), nameNode->value_size());
            int cooldown= stoi(time);
            delete this->loaded1;
            this->loaded1=new PowerLoaded(name, cooldown, 30);
        }
    }
}
/**
 * @brief if not loaded the power, release a loaded and store a new value
 * @param powerName string
 */
void Strategies::checkIfLoaded(std::string powerName) {
    if(this->loaded1->getName()!=powerName && this->loaded2->getName()!=powerName){
        int powerNumber;
        if(powerName=="Deathray"){
            powerNumber=1;
        }else if(powerName=="Flashstep"){
            powerNumber=2;
        } else if(powerName=="Invinsible"){
            powerNumber=3;
        }else if(powerName=="Fireball"){
            powerNumber=4;
        }

        loadPower1(powerNumber);
        std::cout<<"loaded new value"<<std::endl;
        std::cout<<"loaded: "<<powerName<<std::endl;
    }else{
        std::cout<<"Is loaded: "<<powerName<<std::endl;
    }
}
