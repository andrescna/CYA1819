#include "block.hpp"

block::block()
{
    blockHeight = 1;
    blockLenght = 1;
}

block::block(int l, int h)
{
    blockLenght = l;
    blockHeight = h;
}


int block::get_lenght(){
    return (blockLenght);
}

int block::get_height(){
    return (blockHeight);
}


block::~block(){}