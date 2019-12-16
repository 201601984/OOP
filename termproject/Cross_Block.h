#ifndef CROSS_BLOCK_H
#define CROSS_BLOCK_H

#include "Big_Block.h"

class Array_2d;
class Cross_Block : public Big_Block {
private:
protected:
    void rotate();
public:
    Cross_Block(Array_2d* array_2d, Color c1, Color c2, Color c3, Color c4, Color c5);
};

#endif
