#include "common.hpp"



// Calculates the valid rows set for a given wall length and block sizes

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
        cout << "holasfilas" << endl;
        cout << validRows.size() << endl;

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
            cout << "holasfilas" << endl;
            cout << validRows.size() << endl;

        }

        if (temp.get_last() > wallLength){

            temp.erase_block();
        }
    }
}


// Calculates all valid walls with a precalculated valid rows set

vector<wall> calc_valid_walls(vector<row> validRows, int wallLength, int wallHeight)
{
    vector<wall> validWalls;

    wall temp(wallLength,wallHeight);

    calc_row_order(validWalls, validRows, temp);


    return validWalls;
}

void calc_row_order(vector<wall> &validWalls, vector<row> validRows, wall temp)
{







}
