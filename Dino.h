//
// Created by nicki on 01.05.2024.
//

#ifndef DINOPROJECT_DINO_H
#define DINOPROJECT_DINO_H
#include <SFML/Graphics.hpp>

class Dino {
    public:
    Dino();
    sf::Sprite getSprite();
    float getJumpSpeed();
    void jump();
    void setJumpSpeed(float jsp);
    float getScore();
    void setScore(float val);
    void setPosition(int x, int y);
private:
    float score;
    sf::Texture texture;
    sf::Sprite sprite;
    float jumpSpeed;
};


#endif //DINOPROJECT_DINO_H
