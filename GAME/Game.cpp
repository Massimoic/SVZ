//
// Created by massi on 10/6/2018.
//

#include "Game.h"
#include "LoaderManager.hpp"
//#include "Character.h"
#include "Scenario.hpp"
#include "ECS/Components.hpp"

SDL_Renderer* Game::renderer = nullptr;

//Character* player;
//Character* enemy;

//Scenario* map;

Manager manager;
auto& player(manager.addEntity());

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen) {
    
    int flags = 0;
    
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
        std::cout << "window fullscreen" << std::endl;
    }
    
    if(SDL_Init(SDL_INIT_VIDEO) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        std::cout << "window created" << std::endl;
        
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //window color
        }
        
        running_game = true;
    }
    else {
        running_game = false;
        
    }
    
    //player = new Character("/Users/andreadiaz/projects/GAME/personajes/spy1.png", 0, 334);
//    enemy = new Character("/Users/andreadiaz/projects/GAME/personajes/zombie.png", 100, 334);
    //map = new Scenario();
    
    player.add_component<TranformComponent>();
    player.add_component<Sprite>("/Users/andreadiaz/projects/GAME/personajes/spy1.png");
    
    
}

void Game::events() {
    SDL_Event event;
    
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            running_game = false;
            std::cout << "game quitted" << std::endl;
            break;
            
        default:
            break;
    }
}

void Game::update() {
    //here is gonna be all the game objects ex. player and enemies
//    player -> Update();
//    enemy -> Update();
    manager.update();
//    std::cout << newPlayer.GetComponent<TranformComponent>().x() << ", " << newPlayer.GetComponent<TranformComponent>().y() << std::endl;
}

void Game::render() { //here you are gonna put the things you wanna show on the screen
    SDL_RenderClear(renderer);
    //map -> DrawScenario();
//    player -> Render();
//    enemy -> Render();
    manager.draw();
    SDL_RenderPresent(renderer); //add things to window
}

void Game::clean() {
    std::cout << "game clean" << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::GameOver() {

}
