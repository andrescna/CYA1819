#include "wall.hpp"


wall::wall()
{
    wallLenght = 1;
    wallHeight = 1;
}


wall::wall(int l, int h)
{
    wallLenght = l;
    wallHeight = h;
}


void wall::insert_row(row lastRow)
{
    wall_.push_back(lastRow);
}

void wall::erase_row()
{
    wall_.pop_back();
}


int wall::get_height()
{
    return wallHeight;
}

int wall::get_length()
{
    return wallLenght;
}

int wall::get_wall_rows()
{
    return wall_.size();
}

void wall::clear_rows()
{
    wall_.clear();

}


ostream& wall::write(ostream& os){

    for (int i=0; i<wallHeight; i++){
        wall_[i].write(os);
    }

    cout << endl; 
    return os;
}


wall::~wall(){}