//
// Created by massi on 10/6/2018.
//

#include "Game.h"
#include "LoaderManager.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"

SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;

Manager manager;
auto& background_level(manager.addEntity());
auto& zombie(manager.addEntity());
auto& spy(manager.addEntity());
auto& floor_limit(manager.addEntity());


Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int x_pos, int y_pos, int width, int height) {
    
    int flags = 0;
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        std::cout << "window created" << std::endl;
        
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //window color
            background_level.add_component<TransformComponent>(0.0f, -50.0f, 680, 480);
            background_level.add_component<Sprite>("back-prueba.png");
        }
        
        running_game = true;
    }
    else {
        running_game = false;
        
    }

    // ------------------- P L A Y E R -------------------
    spy.add_component<TransformComponent>(1.0f, 295.0f);
    spy.add_component<Sprite>("spy.png", true);
    spy.add_component<KeyboardController>();
    spy.add_component<ColliderComponent>("player");
    
    // -------------------- E N E M Y --------------------
    zombie.add_component<TransformComponent>(600.0f, 310.0f, 54, 81);
    zombie.add_component<Sprite>("zombie-rest.png");
    
    // -------------------- F L O O R --------------------
    floor_limit.add_component<TransformComponent>(0.0f, 392.0f, 680, 88);
    floor_limit.add_component<Sprite>("floor.png");
    floor_limit.add_component<ColliderComponent>("floor_limit");
    
}

void Game::events() {
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

void Game::update() { //here is gonna be all the game objects ex. player and enemies
    manager.refresh();
    manager.update();
    
    if (Collision::AABB(spy.GetComponent<ColliderComponent>().collider, floor_limit.GetComponent<ColliderComponent>().collider)) {
        spy.GetComponent<TransformComponent>().velocity * -1;
    }
    
    if (spy.GetComponent<TransformComponent>().position.x < 0) {
        spy.GetComponent<TransformComponent>().velocity * -5;
    }
    
    if (spy.GetComponent<TransformComponent>().position.x > 613) {
        spy.GetComponent<TransformComponent>().velocity * -5;
    }
}

void Game::render() { //here you are gonna put the things you wanna show on the screen
    SDL_RenderClear(renderer);
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
