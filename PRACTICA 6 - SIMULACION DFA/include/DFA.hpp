#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "state.hpp"


class DFA{

     private:

    int totalStates_; // o unsigned??
    char initialState_;
    set<state> setStates_; //o un vector??

    public:

    DFA();
    ~DFA();
    
    // aquí mete un vector<string>* separarString(string linea); hará falta????
    
    // Class DFA methods
    int read_DFA(string file);
    void show_DFA();
    void calc_death_states();
    int analyze_word(string word); 

    private:

};