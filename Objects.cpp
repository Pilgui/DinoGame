//
// Created by nicki on 20.04.2024.
//

#include "Objects.h"
#include "Window.h"
#include "Dino.h"
#include <iostream>

Objects::Objects() {
    Objects::speedObjects = -2.5f;
}
Objects::Objects(int x, int y, sf::Texture& texture) {
    if(!texture.loadFromFile("sprites\\block.png")){
        return;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (100, 100, x, y));
    sprite.setPosition(Window::getXSize()+50,Window::getYSize()/2);
}

void Objects::update(std::vector<Objects>& objVec) {
    int randomNum = (rand() % 3) + 1;
    switch (randomNum) {
         case 1:
            objVec.emplace_back(Objects(30, 60, texture));
            break;
         case 2:
            objVec.emplace_back(Objects(30, 40, texture));
            break;
         case 3:
            objVec.emplace_back(Objects(20, 30, texture));
            break;
        }

}

void Objects::objectMove(std::vector<Objects>& objVec) {
    for (int i = 0; i < objVec.size(); ++i) {
        objVec[i].sprite.move(speedObjects,0);

        if(objVec[i].sprite.getPosition().x < -50){
            auto iter = objVec.begin() + i;
            objVec.erase(iter);
        }
    }
}

void Objects::draw(sf::RenderWindow& window, std::vector<Objects>& objVec) {
    for (int i = 0; i < objVec.size(); ++i) {
        window.draw(objVec[i].sprite);
    }
}

sf::Sprite Objects::getSprite() {
    return Objects::sprite;
}

void Objects::setSpeedObj(float val) {
    speedObjects = val;
}

float Objects::getObjSpeed() {
    return speedObjects;
}

void Objects::reset(std::vector<Objects>& objVec) {
    objVec.erase(objVec.begin(),objVec.end());
}





