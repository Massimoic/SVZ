//
// Created by massi on 10/10/2018.
//

#ifndef PROYECTO_ANIMATIONCONTROLLER_H
#define PROYECTO_ANIMATIONCONTROLLER_H


struct Animation {
    int index;
    int speed;
    float myGravity = 0.2f;
    float maxFallSpeed = -5.0f;
    float myJumpForce = 5.0f;
    float curJumpForce = 0.0f;
    float deltaTime;
    
    Animation(){}
    Animation(int i, int s) {
        index = i;
        speed = s;
    }
};


#endif //PROYECTO_ANIMATIONCONTROLLER_H
