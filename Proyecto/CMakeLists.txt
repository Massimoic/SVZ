cmake_minimum_required(VERSION 3.10)
project(Proyecto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto main.cpp Game.cpp Game.h Player.cpp Player.h Enemy.cpp Enemy.h AnimationController.cpp AnimationController.h SoundManager.cpp SoundManager.h Weapon.cpp Weapon.h ScoreManager.cpp ScoreManager.h)