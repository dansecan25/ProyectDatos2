//
// Created by dansecan on 27/03/23.
//

#ifndef PROYECTDATOS2_WINDOWSTATE_H
#define PROYECTDATOS2_WINDOWSTATE_H
#include <SFML/Graphics.hpp>
#include <vector> //temporary

class WindowState {
private:

    sf::RenderTarget* window;
    std::vector<sf::Texture> textures;//change to a linked list

public:
    explicit WindowState(sf::RenderTarget* window);
    virtual ~WindowState();
    virtual void endState()=0;

    virtual void gameUpdate(const float& dt)=0;
    virtual void gameRender(sf::RenderTarget * target)=0;

};


#endif //PROYECTDATOS2_WINDOWSTATE_H
