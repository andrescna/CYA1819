#pragma once

#include <set>
#include <string>

using namespace std;


class alphabet {

    public:

    alphabet();
    alphabet(const string);
    ~alphabet();

    void parse_alphabet(); /*aquíhabráqueverquépones*/  //esto no va a ir aquí


    private:

    set<string> symbols_;
    
};


