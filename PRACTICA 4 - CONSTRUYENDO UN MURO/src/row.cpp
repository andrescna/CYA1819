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



int row::get_last()
{
    return row_.back();
}

int row::get_row_size()
{
    return row_.size();
}

int row::get_row_element(int i)
{
    return row_[i];
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


//////////////////////////////////// Calculates the valid rows set for a given wall length and block sizes

vector<row> calc_valid_rows(block block1, block block2, int wallLength)
{
    vector<row> validRows;
    row temp(wallLength, block1.get_height());
  
    calc_next_block(validRows, temp, block1.get_lenght(), block2.get_lenght(), wallLength);

    return validRows;
}



// Main row calculation function. Calculates all possible rows recursively

void calc_next_block(vector<row> &validRows, row temp, int b1_l, int b2_l, int wallLength){

    bool test=false;
    temp.insert_block(b1_l+temp.get_last());
    
    if (temp.get_last() < wallLength) {
        test = true;
        calc_next_block(validRows,temp,b1_l,b2_l,wallLength);
    }

    if (temp.get_last() == wallLength){

        validRows.push_back(temp);
    }

    if (temp.get_last() > wallLength){

        temp.erase_block();
    }

    if ((temp.get_last() < wallLength) && (test==true)){

            temp.erase_block();

            temp.insert_block(b2_l+temp.get_last());
    
            if (temp.get_last() < wallLength) {
                    test = true;
                    calc_next_block(validRows,temp,b1_l,b2_l,wallLength);
            }

            if (temp.get_last() == wallLength){
                    validRows.push_back(temp);
            }

            if (temp.get_last() > wallLength){
                    temp.erase_block();
            }
    }
}

