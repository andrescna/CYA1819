#pragma once

#include "block.hpp"
#include <vector>
#include <iostream>

using namespace std;

class row{

    public:

    row();
    row(int, int);
    ~row();

    void insert_block(int);
    void erase_block();
    
    int get_last();
    int get_row_size();
    int get_row_element(int);
    
    ostream& write(ostream&);

   
    private:

    int rowLenght;
    int rowHeight;
    
    vector<int> row_;
    
};

vector<row> calc_valid_rows(block, block, int);
void calc_next_block(vector<row> &, row, int, int, int);