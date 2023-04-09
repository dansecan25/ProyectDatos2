//
// Created by dansecan on 30/03/23.
//

#include "../Headers/Entities.h"

Entities::Entities() {
    this->initVariables();
}

Entities::~Entities() {
    delete this->sprite;
}
/**
 * @brief moves the sprite
 * @param dt const float reference
 * @param x const float
 * @param y const float
 */
void Entities::move(const float& dt,const float x, const float y) {
    this->sprite->move(x*this->movementSpeed*dt,y*this->movementSpeed*dt);
}

void Entities::updateEntity(const float &dt) {

}
/**
 * @brief draws the sprite in the window
 * @param target sf::RenderTarget pointer
 */
void Entities::renderEntity(sf::RenderTarget *target) {
    target->draw(*this->sprite);
}
/**
 * @brief gives the sprite a texture
 * @param texture string with the route to the texture
 */
void Entities::giveTexture(std::string texture) {
    sf::Texture* textureT=new sf::Texture();
    textureT->loadFromFile(texture);
    this->spriteTexture=textureT;
    this->sprite= new sf::Sprite(*this->spriteTexture);
}
/**
 * @brief initiates the entity variables
 */
void Entities::initVariables() {
    this->movementSpeed=100;

}
/**
 * @brief sets the entity starting position
 * @param x const float
 * @param y const float
 */
void Entities::setPosition(const float x, const float y) {
    this->sprite->setPosition(x,y);
}
