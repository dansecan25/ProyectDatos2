//
// Created by dansecan on 11/03/23.
//

#include "../Headers/MainScreen.h"

MainScreen::MainScreen() {
    RenderWindow window(VideoMode(1000, 600), "Battle Space Project", sf::Style::Titlebar | sf::Style::Close);
    sf::Texture t;
    //t=ImageLoader::getInstance()->getTexture("../Resources/images/SpaceBackground.jpg");
    t.loadFromFile("../Resources/Images/SpaceBackground.jpg");
    sf::Sprite s(t);
    while (window.isOpen())
    {
        Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(s);
        window.display();
    }

}