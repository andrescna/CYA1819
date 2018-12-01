#pragma once

#include <string>
#include <fstream>
#include <iostream>

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
    int is_DFA();
    int analyze_word(string word); 

};