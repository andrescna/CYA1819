#pragma once

#include "block.hpp"
#include <vector>
#include <iostream>

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