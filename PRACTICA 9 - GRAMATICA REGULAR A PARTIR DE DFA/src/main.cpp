/**
@file main.cpp

@mainpage

CYA 2018-19.
PRACTICA 9 - GRAMATICA REGULAR A PARTIR DE DFA.

@author Andrés Concepción Afonso
@date 10/12/2018
*/

#include "DFA.hpp"
#include "GR.hpp"

#include <iostream>
#include <set>

using namespace std;

/*! Programa principal */

int main(int argc, char** argv){
    
    cout << endl;
    cout << "—————————————————————————————————————————————————" << endl;
    cout << "| CYA 1819 — Práctica 9 - GR a partir de un DFA |" << endl;
    cout << "—————————————————————————————————————————————————" << endl;
    cout << "Crea una GR a partir de un DFA " << endl << endl;


    ////////////////////////////// MAIN MENU ///////////////////////////////////

    DFA dfa;
    GR grammar;

    if (argc != 3) {
        cout << "\e[1mERROR\e[0m. Argumentos insuficientes o excesivos" << endl << endl;
        cout << "El formato de entrada es: " << endl << endl;
        cout << "\e[1m./GRsim [dfa de entrada] [gramatica de salida]\e[0m." << endl << endl;
        cout << "O si se ejecuta con make: " << endl << endl;
        cout << "\e[1mmake run ARG=\"[dfa de entrada] [gramatica de salida]\"\e[0m." << endl << endl;;

        return(1);
    }    
 
    cout << "-> DFA de entrada: \t\t" << argv[1] << endl;
    cout << "-> Gramática de salida: \t" << argv[2] << endl;


    /// MIRA A VER LOS ARGUMENTOS!!!

    /*//debug //////////////////////////
        nfa.read_NFA(default_filename);
        nfa_loaded=true;
        end_loop2=true;
    //debug //////////////////////////*/
    
    if (dfa.read_DFA(argv[1])==!0) {  //revisa qué va en el nombre
        cout << "\e[1mERROR\e[0m. No se ha podido cargar el DFA" << endl;
        return(1);
    }



    
}