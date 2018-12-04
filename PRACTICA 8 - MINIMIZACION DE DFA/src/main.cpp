/**
@file main.cpp

@mainpage

CYA 2018-19.
PRACTICA 8 - MINIMIZACIÓN DE DFA.

@author Andrés Concepción Afonso
@date 10/12/2018
*/

#include "NFA.hpp"

#include <iostream>
#include <set>

using namespace std;

/*! Programa principal */

int main(){
    
    cout << endl;
    cout << "———————————————————————————————————————————————" << endl;
    cout << "| CYA 1819 — Práctica 8 - Minimizador de DFAs |" << endl;
    cout << "———————————————————————————————————————————————" << endl;
    cout << "Este programa simula un NFA y permite minimizar un DFA " << endl;


    ////////////////////////////// MAIN MENU ///////////////////////////////////

    NFA nfa;
    string default_filename = "nfa.nfa";
    string default_output = "dfa.dfa";      
    string filename;
    string output;
    string word;

    bool end_loop = false;
    bool nfa_loaded = false;
    
    do {
        
        bool end_loop2 = false;
        
 
        cout << endl;
        cout << "—————————————————————————————————————————————" << endl;
        cout << "Por favor seleccione la operación a realizar:" << endl;
        cout << "—————————————————————————————————————————————" << endl << endl;
        cout << "1 - Leer DFA/NFA" << endl << "2 - Mostrar DFA/NFA" << endl;
        cout << "3 - Identificación de estados de muerte" << endl;
        cout << "4 - Identificación estados importantes" << endl;
        cout << "5 - ¿Es un DFA?" << endl << "6 - Analizar cadena" << endl << endl;
        cout << "7 - Minimizar DFA (SOLO PARA DFAs)" << endl;
        cout << "8 - Exportar el DFA a archivo (SOLO PARA DFAs" << endl << endl;
        cout << "x - Salir del programa" << endl << endl;

        cout << "Introduzca una opción" << endl << ">";

        char option[1];

        cin >> option;

        switch (option[0]){

                case '1': // leer nfa
                                 
                        if (nfa_loaded == true) {
                                cout << endl << "\e[1mERROR\e[0m. DFA ya cargado" << endl << endl;
                        }
                        
                        else {
                                cout << endl << "Introduzca un nombre de fichero (o pulse [\e[1md\e[0m]efault para cargar por defecto nfa.nfa)"<< endl;
                                cout << ">";

                                cin >> filename;

                                if (filename == "d") {
                                        filename = default_filename;
                                }

                                int error_creating_nfa = nfa.read_NFA(filename);
                                
                                /*
                                if (error_creating_nfa == 3 ){
                                        cout << endl << "\e[1mERROR\e[0m. DFA mal formateado: múltiples transiciones para el mismo símbolo en un estado." << endl;
                                        end_loop2 = true;
                                        break;
                                }
                                */
                                end_loop2 = true;
                                
                                if (error_creating_nfa == 0){
                                        nfa_loaded = true;
                                }        
                                break;
                                
                        }
                        
                        break;

                case '2':  //mostrar nfa

                        if (nfa_loaded == true)
                                nfa.show_NFA();
                        else  
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un NFA antes de usar esta opción." << endl << endl;
                        break;
                
                case '3':  //estados de muerte

                        if (nfa_loaded == true) {
                                cout << endl;
                                nfa.calc_death_states();
                        }
                        else  
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un NFA antes de usar esta opción." << endl << endl;
                        break;

                case '4': //estados importantes

                        if (nfa_loaded == true) {
                                cout << endl;
                                nfa.calc_important_states();
                        }
                        else  
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un NFA antes de usar esta opción." << endl << endl;
                        break;
                
                case '5': //¿es un DFA

                        if (nfa_loaded == true) {
                                cout << endl;
                                if (nfa.is_DFA()){
                                        cout << "El automata cargado \e[1mES UN DFA\e[0m" << endl;
                                }
                                break;
                        }
                        else  
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un NFA antes de usar esta opción." << endl << endl;
                        break;


                case '6':  //calcular cadena

                        if (nfa_loaded == true) {
                                
                                cout << endl << "Por favor introduzca la cadena a analizar:" << endl << "> ";
                                cin >> word;
                                nfa.analyze_word(word);
                        }        
                        else 
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un NFA antes de usar esta opción." << endl << endl;
                        
                        break;


                case '7': // minimizar DFA

                        if (nfa_loaded == true) {
                                
                                if (nfa.is_DFA()){
                                        nfa.minimize_DFA();
                                }

                                else {
                                        cout << "\e[1mERROR\e[0m. El automata cargado no es un DFA" << endl;
                                        break;
                                }
                        }        
                        
                        else 
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un DFA antes de usar esta opción." << endl << endl;
                        break;

                case '8': //guardar DFA minimizado en archivo

                        if (nfa_loaded == true) {

                                cout << endl << "Introduzca un nombre de fichero (o pulse [\e[1md\e[0m]efault para usar por defecto dfa.dfa)"<< endl;
                                cout << ">";

                                cin >> output;

                                if (output == "d") {
                                        output = default_output;
                                }
                                nfa.write_DFA(output);
                        }        
                        
                        else 
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un NFA antes de usar esta opción." << endl << endl;
                        break;
                

                case 'x':       //exit
                        
                        cout << endl << "Gracias por utilizar el simulador de NFAs" << endl << endl;
                        end_loop = true;
                        end_loop2 = true;
                        break;

                default:
                        cout << endl << "\e[1mERROR\e[0m. Opción no válida." << endl;
                        break;
        }

        // For doing more operatios or exit the program
        /*
        while (end_loop2==false){

                cout << "¿Desea realizar otra operación (y/n)?" << endl << ">";

                char option2[1];
                cin >> option2;

                switch (option2[0]){
                        case 'y':
                                end_loop2=true;
                        break;

                        case 'n':
                                cout << endl << "Gracias por utilizar el simulador de NFAs" << endl << endl;
                                
                                end_loop=true;
                                end_loop2=true;
                        break;

                        default:
                                cout << endl << "\e[1mERROR\e[0m. Opción no válida." << endl;
                        break;
                }
        }*/

    }while (end_loop == false);
    
}