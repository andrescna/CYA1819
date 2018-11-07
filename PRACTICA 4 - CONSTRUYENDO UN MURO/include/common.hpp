#pragma once

#include "wall.hpp"

#include <vector>

using namespace std;

// For calculing valid rows set

vector<row> calc_valid_rows(block, block, int);
void calc_next_block(vector<row> &, row, int, int, int);

// For calculing valid walls set

vector<wall> calc_valid_walls(vector<row>, int, int);
void calc_row_order(vector<wall> &, vector<row>, wall);