#pragma once

#include "block.hpp"
#include <set>

class row{

    public:

    row();
    ~row();

    private:

    set<block> row_;
    
};