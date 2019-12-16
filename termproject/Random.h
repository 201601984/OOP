#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <ctime>

class Random {
private:
    Random();
public:
    static int getRandomBlock();
    static int getRandomColor();
};

#endif
