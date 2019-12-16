#ifndef TREE_BLOCK_H
#define TREE_BLOCK_H

#include "Big_Block.h"

class Array_2d;
class Tree_Block : public Big_Block {
private:
protected:
    void rotate();
public:
    Tree_Block(Array_2d* array_2d, Color c1, Color c2, Color c3);
};

#endif
