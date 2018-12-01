#pragma once

class transition{

    private:

    //cada transición es un par de elementos: carácter y siguiente estado
    char character_;
    char nextState_;
    
    public:

    transition();
    transition(char character, char nextState);
    ~transition();

    char get_character();
    char get_next_state();

    transition& operator=(const transition &rhs);
    int operator==(const transition &rhs) const;
    int operator<(const transition &rhs) const;

};
