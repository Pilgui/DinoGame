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
    Objects(int x ,int y,  sf::Texture& texture);
    void objectMove(std::vector<Objects>& objVec);
    void draw(sf::RenderWindow& window, std::vector<Objects>& objVec);
    void update(std::vector<Objects>& objVec);
    sf::Sprite getSprite();
    void setSpeedObj(float val);
    float getObjSpeed();
    void reset(std::vector<Objects>& objVec);
private:

    Dino dino;
    float speedObjects;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //DINOPROJECT_OBJECTS_H
