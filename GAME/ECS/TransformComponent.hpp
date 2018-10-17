//
//  Position.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 10/17/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef Position_hpp
#define Position_hpp
#include "Components.hpp"

class TranformComponent: public Component {
private:
    int xpos;
    int ypos;
    
public:
    TranformComponent(){
        xpos = 0;
        ypos = 0;
    }
    
    TranformComponent(int x, int y) {
        xpos = x;
        ypos = y;
    }
    
    int x() {return xpos;}
    void x(int x) { xpos = x;}
    
    int y() {return ypos;}
    void y(int y) { ypos = y;}
    
    void init() override {
        xpos = 0;
        ypos = 0;
        
    }
    
    void update() override {
        xpos ++;
        ypos ++;
    }
    
    
    void setPos (int x, int y) {
        xpos = x;
        ypos = y;
    }
    
};
#endif /* Position_hpp */
