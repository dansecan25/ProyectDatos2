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
    WindowState(sf::RenderTarget* window);
    virtual ~WindowState();
    virtual void endState()=0;
    virtual void update(const float& dt)=0;
    virtual void render(sf::RenderTarget * target= nullptr)=0;

};


#endif //PROYECTDATOS2_WINDOWSTATE_H
