//
// Created by dansecan on 30/03/23.
//

#include "../Headers/Entities.h"

Entities::Entities() {
    this->entityShape.setSize(sf::Vector2f(50,50));
    this->entityShape.setFillColor(sf::Color::White);
    this->movementSpeed=100;
}

Entities::~Entities() {

}

void Entities::move(const float& dt,const float x, const float y) {
    this->entityShape.move(x*this->movementSpeed*dt,y*this->movementSpeed*dt);

}

void Entities::updateEntity(const float &dt) {

}

void Entities::renderEntity(sf::RenderTarget *target) {
    target->draw(this->entityShape);
}
