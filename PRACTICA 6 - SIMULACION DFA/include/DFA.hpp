#pragma once


#include "state.hpp"

class DFA{

     private:

    int totalStates_; // o unsigned??
    int initialState_;
    set<state> states_; //o un vector??

    public:

    DFA();
    ~DFA();
    
    // aquí mete un vector<string>* separarString(string linea); hará falta????
    
    // Class DFA methods
    void readDFA(string file);
    void showDFA();
    void calcDeathStates();
    void analyze_word(char* word); 

    private:

};