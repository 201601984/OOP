#ifndef FOLD_BLOCK_H
#define FOLD_BLOCK_H

#include "Big_Block.h"

class Fold_Block : public Big_Block {
private:
protected:
    void rotate();
public:
    Fold_Block(Array_2d* array_2d, Color c1, Color c2, Color c3);
};

#endif
