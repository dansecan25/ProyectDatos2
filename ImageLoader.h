//
// Created by dansecan on 19/03/23.
//

#ifndef PROYECTDATOS2_IMAGELOADER_H
#define PROYECTDATOS2_IMAGELOADER_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class ImageLoader {
private:
    static ImageLoader* instance;
    ImageLoader() {}
    sf::Texture textures;
public:
    static ImageLoader* getInstance();
    sf::Texture& getTexture(const std::string& filename);

};


#endif //PROYECTDATOS2_IMAGELOADER_H
