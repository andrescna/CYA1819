/**
@file main.cpp

@mainpage

CYA 2018-19.
PRACTICA 7 - SIMULADOR NFA.

@author Andrés Concepción Afonso
@date 03/12/2018
*/

#include "NFA.hpp"

#include <iostream>
#include <set>

using namespace std;

/*! Programa principal */

int main(){
    
    cout << endl;
    cout << "————————————————————————————————————————————————————————————————————————————————" << endl;
    cout << "| CYA 1819 — Práctica 7 - Simulador de Autómatas Finitos No Deterministas (NFA) |" << endl;
    cout << "————————————————————————————————————————————————————————————————————————————————" << endl;
    cout << "Este programa simula un NFA cargado desde fichero y su comportamiento para " << endl;
    cout << "una cadena introducida por el usuario" << endl;


    ////////////////////////////// MAIN MENU ///////////////////////////////////

    NFA nfa;
    string default_filename = "nfa.nfa";      
    string filename;
    string word;

    bool end_loop = false;
    bool nfa_loaded = false;
    
    do {
        
        bool end_loop2 = false;
        
 
        cout << endl;
        cout << "—————————————————————————————————————————————" << endl;
        cout << "Por favor seleccione la operación a realizar:" << endl;
        cout << "—————————————————————————————————————————————" << endl << endl;
        cout << "1 - Leer NFA" << endl << "2 - Mostrar NFA" << endl;
        cout << "3 - Identificación de estados de muerte" << endl;
        cout << "4 - Identificación estados importantes" << endl;
        cout << "5 - ¿Es un DFA?" << endl << "6 - Analizar cadena" << endl << endl;
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
                                
                                if (error_creating_nfa == 1 ){
                                        cout << endl << "\e[1mERROR\e[0m. Nombre de fichero no encontrado." << endl;
                                        end_loop2 = true;
                                        break;
                                }

                                if (error_creating_nfa == 2 ){
                                        cout << endl << "\e[1mERROR\e[0m. NFA mal formateado: más de un estado inicial" << endl;
                                        end_loop2 = true;
                                        break;
                                }
                                /*
                                if (error_creating_nfa == 3 ){
                                        cout << endl << "\e[1mERROR\e[0m. DFA mal formateado: múltiples transiciones para el mismo símbolo en un estado." << endl;
                                        end_loop2 = true;
                                        break;
                                }
                                */
                                if (error_creating_nfa == 4 ){
                                        cout << endl << "\e[1mERROR\e[0m. NFA mal formateado: Nº de estados incorrecto." << endl;
                                        end_loop2 = true;
                                        break;
                                }
                                if (error_creating_nfa == 5 ){
                                        cout << endl << "\e[1mERROR\e[0m. NFA mal formateado: Nº de transiciones incorrecto para algún estado." << endl;
                                        end_loop2 = true;
                                        break;
                                }
                                nfa_loaded = true;
                                end_loop2 = true;
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
                                nfa.is_DFA();
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