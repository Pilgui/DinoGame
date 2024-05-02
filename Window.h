//
// Created by nicki on 01.05.2024.
//

#ifndef DINOPROJECT_WINDOW_H
#define DINOPROJECT_WINDOW_H
#include <SFML/Graphics.hpp>
#include "Dino.h"
#include "restartButton.h"
#include "Objects.h"

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

    static unsigned const int xSize;
    static unsigned const int ySize;
    bool isTrueJump;
    void dinoJump();
    sf::Text scoreText;
    sf::Text gameOverText;
    sf::Font font;
    bool isGame;
    void declareScore();
    void restartGame();
    void declareGameOverText();

    void draw();

    void spawnObj(sf::Time &elapsed);
};


#endif //DINOPROJECT_WINDOW_H
