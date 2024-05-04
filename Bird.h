//
// Created by nicki on 04.05.2024.
//

#ifndef DINOPROJECT_BIRD_H
#define DINOPROJECT_BIRD_H
#include <SFML/Graphics.hpp>
#include "random"

class Bird {
public:
    Bird();
    Bird(sf::Texture& texture);
    void spawn(std::vector<Bird>& birdVec,  bool& isSpawned);
    void draw(sf::RenderWindow& window, std::vector<Bird> &birdVec, bool isSpawned);
    void update(std::vector<Bird>& birdVec, bool& isSpawned);
    void setSpeedCloud(float spd);
    sf::Sprite getSprite();
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int randomNum;
    float speedCloud;

    bool isDeleted;
};


#endif //DINOPROJECT_BIRD_H
