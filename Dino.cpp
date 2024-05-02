//
// Created by nicki on 01.05.2024.
//

#include "Dino.h"
#include "Window.h"


Dino::Dino() : jumpSpeed(-5.0f){
    if(!texture.loadFromFile("sprites\\texture.png")){
        return;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (100,100,20,40));
    sprite.setPosition(Window::getXSize()-450,Window::getYSize()/2);
}

void Dino::jump(){
    if(sprite.getPosition().y > Window::getYSize()/2){
        Dino::jumpSpeed = -5.0f;
    }

    sprite.move(0, jumpSpeed);
    Dino::jumpSpeed += 0.10f;


};

void Dino::setJumpSpeed(float jsp) {
    Dino::jumpSpeed = jsp;
}

sf::Sprite Dino::getSprite(){
    return Dino::sprite;
};
float Dino::getJumpSpeed() {
    return Dino::jumpSpeed;
}

float Dino::getScore() {
    return score;
}

void Dino::setScore(float  val) {
    score = val;
}

void Dino::setPosition(int x, int y) {
    sprite.setPosition(x,y);
}
