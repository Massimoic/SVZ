//
//  Scenario.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 10/16/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef Scenario_hpp
#define Scenario_hpp

#include "Game.h"

class Scenario {
private:
    SDL_Rect src, dst;
    SDL_Texture* floor;
    
    int map[20][25];
    
    
public:
    Scenario();
    ~Scenario();
    
    void LoadScenario(int map[21][25]);
    void DrawScenario();
    
};



#endif /* Scenario_hpp */
