//
//  KeyboardController.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 11/5/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef KeyboardController_hpp
#define KeyboardController_hpp

#include "../Game.h"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component {
public:
    TransformComponent *transform;
    Sprite *animation;
    
    
    void init() override {
        transform  = &entity -> GetComponent<TransformComponent>();
        animation = &entity -> GetComponent<Sprite>();
    }
    
    void update() override {
        if (Game::event.type == SDL_KEYDOWN) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform -> velocity.y = -1;
                    animation -> play("run");
                    break;
                    
                case SDLK_UP:
                    transform -> velocity.y = -1;
                    animation -> play("run");
                    break;
                    
                case SDLK_a:
                    transform -> velocity.x = -1;
                    animation -> play("run");
                    break;
                    
                case SDLK_LEFT:
                    transform -> velocity.x = -1;
                    animation -> play("run");
                    break;
                    
                case SDLK_d:
                    transform -> velocity.x = 1;
                    animation -> play("run");
                    break;
                    
                case SDLK_RIGHT:
                    transform -> velocity.x = 1;
                    animation -> play("run");
                    break;
                
                case SDLK_s:
                    transform -> velocity.y = 1;
                    animation -> play("run");
                    break;
                    
                case SDLK_DOWN:
                    transform -> velocity.y = 1;
                    animation -> play("run");
                    break;
                    
                default:
                    break;
            }
        }
        
        if (Game::event.type == SDL_KEYUP) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform -> velocity.y = 0;
                    animation -> play("rest");
                    break;
                    
                case SDLK_UP:
                    transform -> velocity.y = 0;
                    animation -> play("rest");
                    break;
                    
                case SDLK_a:
                    transform -> velocity.x = 0;
                    animation -> play("rest");
                    break;
                    
                case SDLK_LEFT:
                    transform -> velocity.x = 0;
                    animation -> play("rest");
                    break;
                    
                case SDLK_d:
                    transform -> velocity.x = 0;
                    animation -> play("rest");
                    break;
                    
                case SDLK_RIGHT:
                    transform -> velocity.x = 0;
                    animation -> play("rest");
                    break;
                    
                case SDLK_s:
                    transform -> velocity.y = 0;
                    animation -> play("rest");
                    break;
                    
                case SDLK_DOWN:
                    transform -> velocity.y = 0;
                    animation -> play("rest");
                    break;
                    
                default:
                    break;
            }
        }
    }
};
#endif /* KeyboardController_hpp */
