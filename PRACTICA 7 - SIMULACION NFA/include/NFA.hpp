#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "state.hpp"


class NFA{

    private:

    int totalStates_; 
    char initialState_;
    set<state> setStates_;
    set<char> alphabet_;          //METEMOS ALFABETO

    public:

    NFA();
    ~NFA();
    
    int read_NFA(string file);
    void show_NFA();
    void calc_death_states();
    void calc_important_states();
    void is_DFA();
    void analyze_word(string word); 

};