#pragma once

#include "row.hpp"
#include <vector>

using namespace std;

class wall {

    public:

    wall();
    wall(int, int);
    ~wall();

    void insert_row(row);
    void erase_row();

    int get_height();
    int get_length();
    int get_wall_rows();
    void clear_rows();

    ostream& write(ostream&);

    private:

    int wallLenght;
    int wallHeight;
    vector<row> wall_;


};