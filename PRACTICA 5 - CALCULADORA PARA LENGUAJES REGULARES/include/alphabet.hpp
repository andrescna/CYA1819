#pragma once

#include <set>
#include <string>

using namespace std;


class alphabet {

    public:

    alphabet();
    ~alphabet();

    void parse_alphabet(); /*aquíhabráqueverquépones*/


    private:

    set<string> symbols_;
    
};


