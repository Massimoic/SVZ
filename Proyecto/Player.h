//
// Created by massi on 10/10/2018.
//

#ifndef PROYECTO_PLAYER_H
#define PROYECTO_PLAYER_H

#include "Weapon.h"
#include "ScoreManager.h"
#include "AnimationController.h"

class Player {
    protected:
    int PlayerPosition;
    int PlayerSpeed;
    int PlayerDirection;
    int PlayerHealth;
public:
    Player(int pposition, int pspeed, int pdirection, int phealth);
    void DoFire();
    void DoJump();
    void WeapReload();
    void PlayerDamage();
    void PlayerHealthIncrease();

};


#endif //PROYECTO_PLAYER_H
