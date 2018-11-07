#pragma once

#include "row.hpp"
#include <vector>

using namespace std;

class wall {

    public:

    wall();
    wall(int, int);
    ~wall();

    private:

    int wallLenght;
    int wallHeight;
    vector<row> wall_;


};