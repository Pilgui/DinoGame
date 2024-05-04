//
// Created by nicki on 01.05.2024.
//

#ifndef DINOPROJECT_WINDOW_H
#define DINOPROJECT_WINDOW_H
#include <SFML/Graphics.hpp>
#include "Dino.h"
#include "restartButton.h"
#include "Objects.h"
#include "Ground.h"
#include "Cloud.h"
#include "Bird.h"

class Window {
public:
    Window();
    void start();
    static int getXSize();
    static int getYSize();
    void onCollision();
private:
    Objects obj;
    std::vector<Objects> objectVec;

    restartButton restartButton;

    Dino dino;

    sf::Event event;
    sf::RenderWindow window;

    Ground ground;
    std::vector<Ground> groundVec;

    Cloud cloud;
    std::vector<Cloud> cloudVec;

    Bird bird;
    std::vector<Bird> birdVec;

    sf::Text scoreText;
    sf::Text gameOverText;
    sf::Font font;

    static unsigned const int xSize;
    static unsigned const int ySize;
    void dinoJump();

    bool isGame;
    bool isTrueJump;
    bool isBirdSpawn;
    bool isObjSpawned;

    void declareScore();
    void declareGameOverText();

    void draw();
    void spawnObj(sf::Time &elapsed);
    void restartGame();

};


#endif //DINOPROJECT_WINDOW_H
