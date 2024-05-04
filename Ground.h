//
// Created by nicki on 04.05.2024.
//

#ifndef DINOPROJECT_GROUND_H
#define DINOPROJECT_GROUND_H
#include <SFML/Graphics.hpp>

class Ground {
public:
    Ground();
    Ground(int x,  sf::Texture& texture);
    void draw(sf::RenderWindow& window, std::vector<Ground> &groundVec);
    void start(std::vector<Ground>& groundVec);
    void update(std::vector<Ground> &groundVec);
    float getSpeedGround();
    void setSpeedGround(float speedG);
    sf::Sprite getSprite();
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speedGround;
};


#endif //DINOPROJECT_GROUND_H
