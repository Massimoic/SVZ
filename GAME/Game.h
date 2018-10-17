//
// Created by massi on 10/6/2018.
//

#ifndef PROYECTO_GAME_H
#define PROYECTO_GAME_H


#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include "Character.h"
#include "Enemy.h"

class Game {
protected:
    bool running_game;
    SDL_Window* window;
    int move = 0;
    
public:
    Game();
    ~Game();
    void init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen); //check 'bool fullscreen' later
    
    void events();
    void update(); //here is gonna be all the game objects ex. player and enemies
    void render();
    void clean();
    
    bool running(){
        return running_game;
    };
    bool loadMedia();
    
    void GameOver();
    
    static SDL_Renderer* renderer;
};


#endif //PROYECTO_GAME_H