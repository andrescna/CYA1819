//// Andrés Concepción Afonso
//// CYA 2018-19

/// PRACTICA 6 - SIMULADOR DFA ///
/// Este simula un autómata finito determinista o DFA ///

#include "DFA.hpp"

#include <iostream>
#include <set>

using namespace std;


int main(){
    
    cout << endl;
    cout << "——————————————————————————————————————————————————————————————————————————————" << endl;
    cout << "| CYA 1819 — Práctica 6 - Simulador de Autómatas Finitos Deterministas (DFA) |" << endl;
    cout << "—————————————————————————————————————————————————————————————————————————————" << endl;
    cout << "Este programa simula un DFA cargado desde fichero y su comportamiento para " << endl;
    cout << "una cadena introducida por el usuario" << endl;


    ////////////////////////////// MAIN MENU ///////////////////////////////////

    DFA dfa;
    string default_filename = "dfa.dfa";      
    string filename;
    string word;

    bool end_loop = false;
    bool dfa_loaded = false;
    
    do {
        
        bool end_loop2 = false;
 
        cout << endl;
        cout << "—————————————————————————————————————————————" << endl;
        cout << "Por favor seleccione la operación a realizar:" << endl;
        cout << "—————————————————————————————————————————————" << endl << endl;
        cout << "1 - Leer DFA" << endl << "2 - Mostrar DFA" << endl;
        cout << "3 - Identificación de estados de muerte" << endl << "4 - Analizar cadena" << endl << endl;
        cout << "x - Salir del programa" << endl << endl;

        cout << "Introduzca una opción" << endl << ">";

        char option[1];

        cin >> option;

        switch (option[0]){

                case '1': // leer dfa
                                 
                        if (dfa_loaded == true) {
                                cout << endl << "\e[1mERROR\e[0m. DFA ya cargado" << endl << endl;
                        }
                        
                        else {
                                cout << endl << "Introduzca un nombre de fichero (o pulse \e[1md\e[0m para cargar por defecto dfa.dfa)"<< endl;
                                cout << ">";

                                cin >> filename;

                                if (filename == "d") {
                                        filename = default_filename;
                                }

                                int error_creating_dfa = dfa.read_DFA(filename);
                                
                                if (error_creating_dfa == 1 ){
                                        cout << endl << "\e[1mERROR\e[0m. DFA mal formateado o no encontrado" << endl;
                                        end_loop2 = true;
                                        break;
                                }
                                
                                dfa_loaded = true;


                                end_loop2 = true;
                        }
                        
                        break;

                case '2':  //mostrar dfa

                        if (dfa_loaded == true)
                                dfa.show_DFA();
                        else  
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un DFA antes de usar esta opción." << endl << endl;
                        break;
                
                case '3':  //estados de muerte

                        if (dfa_loaded == true) {
                                cout << endl;
                                dfa.calc_death_states();
                        }
                        else  
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un DFA antes de usar esta opción." << endl << endl;
                        break;

                case '4':  //calcular cadena

                        if (dfa_loaded == true) {
                                
                                cout << endl << "Por favor introduzca la cadena a analizar:" << endl << "> ";
                                cin >> word;
                                dfa.analyze_word(word);
                        }        
                        else 
                                cout << endl << "\e[1mERROR\e[0m. Por favor cargue un DFA antes de usar esta opción." << endl << endl;
                        
                        break;

                case 'x':       //exit
                        
                        cout << endl << "Gracias por utilizar el simulador de DFAs" << endl << endl;
                        end_loop = true;
                        end_loop2 = true;
                        break;

                default:
                        cout << endl << "\e[1mERROR\e[0m. Opción no válida." << endl;
                        break;
        }

        // For doing more operatios or exit the program

        while (end_loop2==false){

                cout << "¿Desea realizar otra operación (y/n)?" << endl << ">";

                char option2[1];
                cin >> option2;

                switch (option2[0]){
                        case 'y':
                                end_loop2=true;
                        break;

                        case 'n':
                                cout << endl << "Gracias por utilizar el simulador de DFAs" << endl << endl;
                                
                                end_loop=true;
                                end_loop2=true;
                        break;

                        default:
                                cout << endl << "\e[1mERROR\e[0m. Opción no válida." << endl;
                        break;
                }
        }

    }while (end_loop == false);
    
}