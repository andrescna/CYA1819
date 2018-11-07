#include "row.hpp"

row::row()
{
    rowLenght = 1;
    rowHeight = 1;
}

row::row(int l, int h)
{
    rowLenght = l;
    rowHeight = h;
    row_.push_back(0);
}



void row::insert_block(int lastBlock)
{
    row_.push_back(lastBlock);
}

void row::erase_block()
{
    row_.pop_back();
}



int row::get_last(){

    return row_.back();
}






// metodo para pinar filas
ostream& row::write(ostream& os){

    int j=0;
    for (int i=0; i<=rowLenght; i++){
        
        if (i==0){
            os << "|";
            j++;
        }

        else
            if (i==rowLenght)
                os << "x|";
            
            else
                if (row_[j] == i) {
                os << "x|";
                j++;
                }
                else
                os << "x";
        

    }
    os << endl;
    return os;

}


row::~row()
{

}