#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "state.hpp"


class DFA{

    private:

    int totalStates_; 
    char initialState_;
    set<state> setStates_;

    public:

    DFA();
    ~DFA();
    
    int read_DFA(string file);
    void show_DFA();
    void calc_death_states();
    int analyze_word(string word); 

};