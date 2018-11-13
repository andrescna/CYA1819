#pragma once

#include <set>

#include "word.hpp"


class alphabet {

    public:

    alphabet();
    alphabet(const word);
    ~alphabet();

    set<word> get_symbols();
    void insert_symbol(word symbol);
    bool is_symbol_in_alphabet(word symbol);


    void parse_alphabet(); /*aquíhabráqueverquépones*/  //esto no va a ir aquí


    private:

    set<word> symbols_;
    
};


