//
//  Sprite.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 10/17/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "Components.hpp"
#include <SDL2/SDL.h>

class Sprite: public Component {
private:
    TranformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, dstRec;
    
public:
    Sprite() = default;
    
    Sprite(const char* path) {
        texture = LoaderManager::LoadTexture(path);
        
    }
    
    void init() override {
        transform = &entity -> GetComponent<TranformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = 150;
        srcRect.h = 204;
        dstRec.w = 63;
        dstRec.h = 90;
    }
    
    void update() override {
        dstRec.x = transform -> x();
        dstRec.y = transform -> y();
    }
    
    void draw() override {
        LoaderManager::Draw(texture, srcRect, dstRec);
    }
    
};
#endif /* Sprite_hpp */
