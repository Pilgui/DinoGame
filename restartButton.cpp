//
// Created by nicki on 23.04.2024.
//

#include "restartButton.h"

restartButton::restartButton(int x, int y, int width, int height) {
    if(!texture.loadFromFile("sprites\\texture.png")){
        return;
    }
    if(!font.loadFromFile("Fonts\\ops.ttf")){
        return;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (100,100,width,height));
    text.setFont(font);
    text.setCharacterSize(20);
    text.setString("Restart game");
    text.setFillColor(sf::Color::Black);

    sprite.setPosition(x,y);
    text.setPosition(x+30,y+10);

}

void restartButton::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(text);
}

bool restartButton::isClicked(sf::RenderWindow &window) {
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    if(sprite.getGlobalBounds().contains(mousePos)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            return true;
        }
    }
    return false;
}
