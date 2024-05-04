//
// Created by nicki on 04.05.2024.
//

#ifndef DINOPROJECT_CLOUD_H
#define DINOPROJECT_CLOUD_H
#include <SFML/Graphics.hpp>
#include "random"

class Cloud {
public:
    Cloud();
    Cloud(int y,  sf::Texture& texture);
    void start(std::vector<Cloud>& cloudVec);
    void draw(sf::RenderWindow& window, std::vector<Cloud> &cloudVec);
    void update(std::vector<Cloud>& cloudVec);
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int randomNum;
};


#endif //DINOPROJECT_CLOUD_H
