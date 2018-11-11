/// Class language, for storing languages. Supports finite and infinite languages

#pragma once

#include "word.hpp"

class language {

    public:

    language(const string);
    ~language();



    private:
    alphabet alphabet_;
    set<word> words_;

};

void add_second_language();

//mete aquí las operaciones con lenguajes :D