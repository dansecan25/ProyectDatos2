//
// Created by dansecan on 30/03/23.
//

#ifndef PROYECTDATOS2_ENTITIES_H
#define PROYECTDATOS2_ENTITIES_H
#include <SFML/Graphics.hpp>
#include <vector> //temporary

class Entities {
private:
    void initVariables();
public:
    Entities();
    ~Entities();
    virtual void move(const float& dt, const float x, const float y);
    void giveTexture(std::string texture);
    virtual void updateEntity(const float& dt);
    virtual void renderEntity(sf::RenderTarget* target);
    virtual void setPosition(const float x, const float y);

protected:
    sf::Sprite* sprite;
    sf::Texture* spriteTexture;
    float movementSpeed;










};


#endif //PROYECTDATOS2_ENTITIES_H
