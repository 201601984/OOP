#ifndef BIG_BLOCK_H
#define BIG_BLOCK_H

#include "Block.h"
#include <vector>
#include "IOManager.h"

class Big_Block : public Block {
private:
protected:
    int minX, minY, maxX, maxY;
    bool find(Block* b);
    bool canRight();
    bool canLeft();
    bool canDown();
    virtual void rotate()=0;
    void right();
    void left();
    bool down();
    bool down_All();
public:
    Big_Block(Array_2d* array_2d);
    std::vector<Block*> v;
    bool move(char key);
};

#endif
