//
// Created by dansecan on 30/03/23.
//

#include "../Headers/Entities.h"

Entities::Entities() {
    this->movementSpeed=100;
}

Entities::~Entities() {
    delete this->sprite;
}

void Entities::move(const float& dt,const float x, const float y) {
    if(this->sprite){
        this->sprite->move(x*this->movementSpeed*dt,y*this->movementSpeed*dt);
    }

}

void Entities::updateEntity(const float &dt) {

}

void Entities::renderEntity(sf::RenderTarget *target) {
    target->draw(this->entityShape);
}
