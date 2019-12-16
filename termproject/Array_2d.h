#ifndef ARRAY_2D_H
#define ARRAY_2D_H

#include "Block.h"
#include "Big_Block.h"

class Array_2d {
private:
    Block* block_Array[5][12];
    void init();
public:
    static const int WIDTH = 5;
    static const int HEIGHT = 12;
    Array_2d();
    Block* getBlock(int x, int y);
    void clean(Block* block);
    void clean(Big_Block* big_Block);
    void spawn(Block* block);
    void spawn(Big_Block* big_Block);
    void show();
    bool canMake(Big_Block* big_Block);
};

#endif
