//
// Created by nicki on 01.05.2024.
//

#ifndef DINOPROJECT_OBJECTS_H
#define DINOPROJECT_OBJECTS_H
#include <SFML/Graphics.hpp>
#include "Dino.h"

class Objects {
public:
    Objects();
    Objects(sf::Texture& texture);
    void objectMove(std::vector<Objects>& objVec, bool& isSpawned);
    void draw(sf::RenderWindow& window, std::vector<Objects>& objVec, bool& isSpawned);
    void spawn(std::vector<Objects>& objVec,  bool& isSpawned);
    sf::Sprite getSprite();
    void setSpeedObj(float val);
    float getObjSpeed();
    void reset(std::vector<Objects>& objVec);
private:

    Dino dino;
    float speedObjects;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Sprite sprite;

    bool isDeleted = false;
};


#endif //DINOPROJECT_OBJECTS_H
