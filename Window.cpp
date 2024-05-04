//
// Created by nicki on 20.04.2024.
//

#include "Window.h"
#include <iostream>
#include <string>
unsigned const int Window::xSize = 500;
unsigned const int Window::ySize = 300;

Window::Window() : window(sf::VideoMode(xSize, ySize), "Dino") ,
                   restartButton(xSize/2,ySize/4,200,50),
                   isGame(true),isTrueJump(false),isBirdSpawn(false),isObjSpawned(true)
{
    dino.setScore(0);
    objectVec.reserve(5);
    birdVec.reserve(3);

    declareScore();
    declareGameOverText();
    start();
}




void Window::start() {
    obj.spawn(objectVec,isObjSpawned);
    ground.start(groundVec);
    cloud.start(cloudVec);

    const int targetFPS = 60;
    const sf::Time timePerFrame = sf::seconds(1.0f / targetFPS);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::Clock clockObj;
    sf::Time elapsed = sf::Time::Zero;

    while(window.isOpen()){
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
                isTrueJump = true;
            }
        }
        if(restartButton.isClicked(window)){
            restartGame();
        }


        while (timeSinceLastUpdate > timePerFrame){
            timeSinceLastUpdate -= timePerFrame;

            elapsed += clockObj.restart();
            if(isGame){
                dinoJump();
                ground.update(groundVec);
                cloud.update(cloudVec);

                spawnObj(elapsed);
                obj.objectMove(objectVec,isObjSpawned);
                bird.update(birdVec,isBirdSpawn);

                dino.setScore(dino.getScore() + 0.35f);
                scoreText.setString("Score"+std::to_string((int)dino.getScore()));

                if(dino.getScore() >= 100){
                    obj.setSpeedObj(obj.getObjSpeed() + -0.0005f);
                    ground.setSpeedGround(obj.getObjSpeed() + -0.0005f);
                    bird.setSpeedCloud(obj.getObjSpeed() + -0.0005f);
                }

                onCollision();
            }
        }

        window.clear(sf::Color::White);
        draw();
        window.display();
    }
}

void Window::spawnObj(sf::Time &elapsed) {
    if (dino.getScore() < 500) {
        if (elapsed >= sf::seconds(2.5)) {
            isObjSpawned = true;
            obj.spawn(objectVec,isObjSpawned);
            elapsed = sf::Time::Zero;
        }
    }else if(dino.getScore() >= 500 && dino.getScore() < 1500){
        if(elapsed >= sf::seconds(2)){
            int randNum = rand()%5 + 1;
            if(randNum <= 3){
                isObjSpawned = true;
                obj.spawn(objectVec,isObjSpawned);
                elapsed = sf::Time::Zero;
            } else{
                isBirdSpawn = true;
                bird.spawn(birdVec,isBirdSpawn);
                elapsed = sf::Time::Zero;
            }
        }
    } else if (dino.getScore() >= 1500){
        if(elapsed >= sf::seconds(1.5)){
            int randNum = rand()%5 + 1;
            if(randNum <= 3){
                isObjSpawned = true;
                obj.spawn(objectVec,isObjSpawned);
                elapsed = sf::Time::Zero;
            } else{
                isBirdSpawn = true;
                bird.spawn(birdVec,isBirdSpawn);
                elapsed = sf::Time::Zero;
            }
        }
    }
}

void Window::draw() {
    if(isGame) {
        cloud.draw(window,cloudVec);
        window.draw(dino.getSprite());
        window.draw(scoreText);
        obj.draw(window, objectVec,isObjSpawned);
        ground.draw(window, groundVec);
        bird.draw(window,birdVec, isBirdSpawn);
    } else{
        window.draw(gameOverText);
        window.draw(scoreText);
        restartButton.draw(window);
    }
}


void Window::onCollision() {
    for (int i = 0; i < objectVec.size(); ++i) {
        if(dino.getSprite().getGlobalBounds().intersects(objectVec[i].getSprite().getGlobalBounds()) ||
                dino.getSprite().getGlobalBounds().intersects(birdVec[i].getSprite().getGlobalBounds())){
            isGame = false;
        }
    }
};


void Window::dinoJump() {
    if (isTrueJump) {
        dino.jump();
        if(dino.getJumpSpeed() > 5){
            dino.setJumpSpeed(-5.0f);
            isTrueJump = false;
        }
    }
}
void Window::restartGame() {
    isGame = true;
    dino.setScore(0);
    obj.reset(objectVec);
    dino.setPosition(window.getSize().x-450,window.getSize().y/2);
}


void Window::declareScore() {
    if(!font.loadFromFile("Fonts\\ops.ttf")){
        return;
    }
    scoreText.setFont(font);
    scoreText.setString("Score  " + std::to_string(dino.getScore()));
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(380, 10);

}

void Window::declareGameOverText() {
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(40);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
}
//


int Window::getXSize(){
    return Window::xSize;
};
int Window::getYSize(){
    return Window::ySize;
}

