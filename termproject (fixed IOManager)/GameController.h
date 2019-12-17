#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include<stdio.h>
class GameController {
private:
public:
    GameController();
    void make();
    bool inputMove();
    void run();
    static int score;
    void showScore();
};

#endif
