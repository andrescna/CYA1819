/**
@file main.cpp

@mainpage

CYA 2018-19.
PRACTICA 9 - GRAMATICA REGULAR A PARTIR DE DFA.

@author Andrés Concepción Afonso
@date 18/12/2018
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
    
    cout << "DFA de entrada: \t" << argv[1] << endl;
    cout << "Gramática de salida: \t" << argv[2] << endl;

    // ERROR. DFA no cargado 
    if (dfa.read_DFA(argv[1])==!0) { 
        cout << "\e[1mERROR\e[0m. No se ha podido cargar el DFA" << endl;
        return(1);
    }
    
    cout << "Convirtiendo... ";

    grammar = dfa.convert_to_GR();

    cout << "Listo." << endl << endl << "\e[1m-> Gramática generada con éxito\e[0m" << endl;

    cout << endl << "La gramática regular generada es:" << endl;
    grammar.show_GR();
    
    cout << endl << "Exportando... ";

    grammar.write_to_file(argv[2]);

    cout << "Listo." << endl << endl;
    cout << "\e[1m-> Grámática exportada con éxito\e[0m" << endl << endl;
    
}