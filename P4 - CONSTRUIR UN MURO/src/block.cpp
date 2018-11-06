#include "block.hpp"



block::block(){
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


block::~block(){

}