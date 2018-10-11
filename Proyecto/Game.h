//
// Created by massi on 10/6/2018.
//

#ifndef PROYECTO_GAME_H
#define PROYECTO_GAME_H

#include "Player.h"
#include "Enemy.h"


class Game {
protected:
    int height;
    int width;
    int background;
public:
    Game(int _height, int _width, int _background);
    void Run();
    void GameOver();
};


#endif //PROYECTO_GAME_H
