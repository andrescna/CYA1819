#pragma once

#include <set>

#include "transition.hpp"

using namespace std;


class state {

    public:




    private:

    set<transition> state_;

    bool initialState;
    bool finalState;
    bool deathState;

};