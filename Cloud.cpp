//
// Created by nicki on 04.05.2024.
//

#include "Cloud.h"
#include "Window.h"

Cloud::Cloud() {
    if(!texture.loadFromFile("sprites\\cloud.png")){
        return;
    }
    sprite.setTexture(texture);
    sprite.setPosition(550,50);
}


Cloud::Cloud(int y,  sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(550 , y);
}

void Cloud::start(std::vector<Cloud>& cloudVec) {
    cloudVec.reserve(1);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(20, 70);
    randomNum = dis(gen);

    cloudVec.emplace_back(Cloud(randomNum, texture));
}

void Cloud::draw(sf::RenderWindow& window, std::vector<Cloud>& cloudVec) {
    window.draw(cloudVec[0].sprite);
}

void Cloud::update(std::vector<Cloud>& cloudVec) {
    cloudVec[0].sprite.move(-1,0);

    if(cloudVec[0].sprite.getPosition().x < -100){
        cloudVec.erase(cloudVec.begin(),cloudVec.end());
        start(cloudVec);
    }
}

void Cloud::reset(std::vector<Cloud> &cloudVec) {

    cloudVec[0].sprite.setPosition(550,50);
}



