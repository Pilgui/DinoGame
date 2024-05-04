//
// Created by nicki on 04.05.2024.
//

#include "Bird.h"
#include "Window.h"

Bird::Bird() {
    speedCloud = -2.5f;

    if(!texture.loadFromFile("sprites\\bird.png")){
        return;
    }
}

Bird::Bird(sf::Texture &texture) {
    sprite.setTexture(texture);
    sprite.setPosition(Window::getXSize()+50,Window::getYSize()/2-50);
}

void Bird::spawn(std::vector<Bird> &birdVec, bool& isSpawned) {
    if (isSpawned) {
        birdVec.emplace_back(Bird(texture));
    }
}

void Bird::draw(sf::RenderWindow &window, std::vector<Bird> &birdVec, bool isSpawned) {
    for (int i = 0; i < birdVec.size();i++) {
        if (isSpawned && !birdVec[0].isDeleted) {
            window.draw(birdVec[i].sprite);
        }
    }
}

void Bird::update(std::vector<Bird> &birdVec, bool& isSpawned) {
    if(isSpawned) {
        for (int i = 0; i < birdVec.size();i++) {

            birdVec[i].sprite.move(speedCloud, 0);

            if (birdVec[i].sprite.getPosition().x < -150) {
                isDeleted = true;
            }
            if (birdVec[i].isDeleted) {
                auto iter = birdVec.begin() + i;
                birdVec.erase(iter);
            }
        }
    }
}

void Bird::setSpeedCloud(float spd) {
    speedCloud = spd;
}

sf::Sprite Bird::getSprite() {
    return sprite;
}

void Bird::reset(std::vector<Bird> &birdVec, bool& isSpawned) {
    if (isSpawned) {
        birdVec.erase(birdVec.begin(), birdVec.end());
    }
}

