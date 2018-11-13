/// Class language, for storing languages. Supports finite and infinite languages

#pragma once

#include "alphabet.hpp"

class language {

    public:

    language();
    ~language();

    alphabet get_alphabet();
    set<word> get_language_elements();
    
    void add_alphabet_symbol();
    void add_word();


    private:
    alphabet alphabet_;
    set<word> words_;

};

language parse_language (string userInput, bool &syntaxError);
void add_second_language();

//mete aquí las operaciones con lenguajes :D