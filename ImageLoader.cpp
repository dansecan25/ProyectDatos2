//
// Created by dansecan on 19/03/23.
//

#include "ImageLoader.h"
ImageLoader* ImageLoader::instance = nullptr;
ImageLoader * ImageLoader::getInstance(){
    if(instance== nullptr) instance= new ImageLoader();
    return instance;
}
sf::Texture& ImageLoader::getTexture(const std::string& filename)
{
    sf::Texture texture;
    texture.loadFromFile(filename);
    textures=texture;
    return textures;
}