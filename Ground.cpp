//
// Created by nicki on 04.05.2024.
//

#include "Ground.h"
#include "Window.h"

Ground::Ground() {
    speedGround = -2.5f;

    if(!texture.loadFromFile("sprites\\ground.png")){
        return;
    }
    sprite.setTexture(texture);
    sprite.setPosition(0,Window::getYSize()/2+35);
}

Ground::Ground(int x, sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(x,Window::getYSize()/2+35);
}

void Ground::start(std::vector<Ground> &groundVec) {
    groundVec.reserve(3);

    groundVec.emplace_back(Ground(0, texture));
    groundVec.emplace_back(Ground(500, texture));
    groundVec.emplace_back(Ground(1000, texture));

}

void Ground::draw(sf::RenderWindow& window, std::vector<Ground> &groundVec) {

    for (int i = 0; i < groundVec.size(); ++i) {
        window.draw(groundVec[i].sprite);
    }
}

void Ground::update(std::vector<Ground> &groundVec) {
    for (int i = 0; i < groundVec.size(); i++) {
        groundVec[i].sprite.move(speedGround, 0);

        if(groundVec[i].sprite.getPosition().x < -500){
            groundVec[i].sprite.setPosition(1000,Window::getYSize()/2+35);
        }
    }
}

float Ground::getSpeedGround() {
    return speedGround;
}

void Ground::setSpeedGround(float speedG) {
    speedGround = speedG;
}

sf::Sprite Ground::getSprite() {
    return sprite;
}





