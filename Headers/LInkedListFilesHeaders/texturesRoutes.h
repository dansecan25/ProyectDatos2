//
// Created by dansecan on 27/03/23.
//

#ifndef PROYECTDATOS2_TEXTURESROUTES_H
#define PROYECTDATOS2_TEXTURESROUTES_H
#include <iostream>

struct textureNodeData{
    std::string dataKey;
    std::string textureData;
};

class texturesStructNode{
public:
    texturesStructNode();
    texturesStructNode(std::string, std::string);
    ~texturesStructNode();
    std::string getCharacter() const;
    std::string getTextureData() const;
    void setData(std::string cDat=" ", std::string textureDat=" ");
    void setNext(texturesStructNode*);
    texturesStructNode* getNext();
private:
    textureNodeData data;
    texturesStructNode* next;


};

class texturesRoutes {
public:
    texturesRoutes();
    void insertNode(std::string cDat,std::string textureDat);
    std::string getNode(std::string);
    void deleteNode(std::string);
    [[nodiscard]] int getLen() const;
    void deleteLast();

private:
    texturesStructNode* head;
    int len;
};


#endif //PROYECTDATOS2_TEXTURESROUTES_H
