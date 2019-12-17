#ifndef COLOR_BLOCK_H
#define COLOR_BLOCK_H

#include <set>

class Block;
class Array_2d;
class Color_Block{
private:
    std::set<Block*> s;
    Array_2d* array_2d;
public:
    static std::set<Color_Block*> explosionS;
    Color_Block(Array_2d* array_2d, Block* b);
    void insert(std::set<Block*> s2);
    std::set<Block*> getSet();
    int getSetSize();
    void explosion();
    void er(Block* b);
};

#endif
