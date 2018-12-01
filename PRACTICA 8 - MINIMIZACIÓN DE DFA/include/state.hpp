#pragma once

#include <set>

#include "transition.hpp"

using namespace std;


class state {

    private:

    char stateId_;
    bool isFinalState_;

    set<transition> transitionSet_; //vector de transiciones

    public:

    state();
    state(char id, char isFinalState);

    char get_stateId();
    bool get_isStateFinal();
    set<transition> get_transitionSet();
    int get_transitionNumber(); 

    void add_transition(char character, char nextState);

    state& operator=(const state &rhs);
    int operator==(const state &rhs) const;
    int operator<(const state &rhs) const;
};
