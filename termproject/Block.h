#ifndef BLOCK_H
#define BLOCK_H

#include "Color.h"
#include "Color_Block.h"

class Array_2d;
class Block {
private:
    Color color = Color::BLANK;
    bool canMerge(Block* b);
    void merge(Block* b);
    void findMerge();
    void setGroup(Color_Block* group);
protected:
    Array_2d* array_2d;
    int x,y;
    Color_Block* group;
public:
    Block(Array_2d* array_2d);
    Block(Array_2d* array_2d, Color color);
    Block(Array_2d* array_2d, int x, int y, Color color);
    Color getColor();
    int getX();
    int getY();
    void setLocation(int x, int y);
    Color_Block* getGroup();
    void down_All();
};

#endif
