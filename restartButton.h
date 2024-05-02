//
// Created by nicki on 01.05.2024.
//

#ifndef DINOPROJECT_RESTARTBUTTON_H
#define DINOPROJECT_RESTARTBUTTON_H
#include <SFML/Graphics.hpp>

class restartButton {
public:
    restartButton(int x, int y, int width, int height);
    void draw(sf::RenderWindow& window);
    bool isClicked(sf::RenderWindow& window);
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Text text;
    sf::Font font;
};


#endif //DINOPROJECT_RESTARTBUTTON_H
