//
// Created by nicki on 20.04.2024.
//

#include "Objects.h"
#include "Window.h"
#include "Dino.h"
#include <iostream>

Objects::Objects() {
    Objects::speedObjects = -2.5f;
    if(!texture1.loadFromFile("sprites\\cactus1.png")){
        return;
    }
    if(!texture2.loadFromFile("sprites\\cactus2.png")){
        return;
    }
    if(!texture3.loadFromFile("sprites\\cactus3.png")){
        return;
    }
}
Objects::Objects(sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(Window::getXSize()+50,Window::getYSize()/2-8);
}

void Objects::spawn(std::vector<Objects>& objVec,  bool& isSpawned) {
    if(isSpawned) {
        int randomNum = (rand() % 3) + 1;
        switch (randomNum) {
            case 1:
                objVec.emplace_back(Objects(texture1));
                break;
            case 2:
                objVec.emplace_back(Objects(texture2));
                break;
            case 3:
                objVec.emplace_back(Objects(texture3));
                break;
        }
    }

}

void Objects::objectMove(std::vector<Objects>& objVec, bool& isSpawned) {
    if (isSpawned) {
        for (int i = 0; i < objVec.size(); ++i) {
            objVec[i].sprite.move(speedObjects, 0);

            if (objVec[i].sprite.getPosition().x < -150) {
                objVec[i].isDeleted = true;
            }

            if(isDeleted){
                auto iter = objVec.begin() + i;
                objVec.erase(iter);
            }
        }
    }
}

void Objects::draw(sf::RenderWindow& window, std::vector<Objects>& objVec, bool& isSpawned) {
    if (isSpawned) {
        for (int i = 0; i < objVec.size(); ++i) {
            if (!objVec[i].isDeleted) {
                window.draw(objVec[i].sprite);
            }
        }
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





