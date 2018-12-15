#include "GR.hpp"

//! Constructor por defecto
GR::GR(){}

//! Constructor
GR::GR(set<char> alphabet, char startSymbol, set<productionSet> productions){
    alphabet_ = alphabet;
    startSymbol_ = startSymbol;
    productions_ = productions;
}

//! Destructor
GR::~GR(){}

///////////////////////////////////////  METODOS DE CLASE DFA ////////////////////////////////////////

//! Mostrar por pantalla
/*!
    Muestra una gramática regular por pantalla
*/
void GR::show_GR(){

    // SIMBOLOS TERMINALES
    cout << endl << alphabet_.size() << endl;
    
    set<char>::iterator i=alphabet_.begin();
    char terminal = *i;
    cout << terminal;
    i++;

    for (int j=0; j<alphabet_.size()-1; j++){
        terminal = *i;
        cout << " " << terminal;
        i++;
    }
    cout << endl;

    //SIMBOLOS NO TERMINALES

    cout << productions_.size() << endl;
    set<productionSet>::iterator k = productions_.begin();
    
    for (int l=0; l<productions_.size(); l++){
        productionSet temp_production_set = *k;
        if(startSymbol_==temp_production_set.get_nonTerminal()){
            cout << temp_production_set.get_nonTerminal();
            break;
        }
        k++;
    }

    k = productions_.begin();

    for (int l=0; l<productions_.size(); l++){
        productionSet temp_production_set = *k;
        if(startSymbol_!=temp_production_set.get_nonTerminal()){
            cout << " " << temp_production_set.get_nonTerminal();
        }
        k++;
    }
    
    cout << endl;

    // PRODUCCIONES
    
    k = productions_.begin();
    
    for (int l=0; l<productions_.size(); l++){
        productionSet temp_production_set = *k;
        if(startSymbol_==temp_production_set.get_nonTerminal()){
            cout << temp_production_set.get_nonTerminal() << " -> ";
            set<string> temp_prod = temp_production_set.get_productions();
            set<string>::iterator m =temp_prod.begin();
            for (int n=0; n<temp_prod.size()-1; n++){
                cout << (*m) << " | ";
                m++;
            }
            cout << (*m) << endl;
            break;
        }
        k++;
    }
    
    k = productions_.begin();
    
    for (int l=0; l<productions_.size(); l++){
        productionSet temp_production_set = *k;
        if(startSymbol_!=temp_production_set.get_nonTerminal()){
            cout << temp_production_set.get_nonTerminal() << " -> ";
            set<string> temp_prod = temp_production_set.get_productions();
            set<string>::iterator m =temp_prod.begin();
            for (int n=0; n<temp_prod.size()-1; n++){
                cout << (*m) << " | ";
                m++;
            }
            cout << (*m);
        }
        k++;
        cout << endl;
    }

}


//! Exportar a archivo
/*!
    Exporta una gramática regular al archivo definido en output
*/
void GR::write_to_file(string output){

    ofstream fs(output, ios::out);
    
    // SIMBOLOS TERMINALES
    fs << alphabet_.size() << endl;
    
    set<char>::iterator i=alphabet_.begin();
    char terminal = *i;
    fs << terminal;
    i++;

    for (int j=0; j<alphabet_.size()-1; j++){
        terminal = *i;
        fs << " " << terminal;
        i++;
    }
    fs << endl;

    //SIMBOLOS NO TERMINALES

    fs << productions_.size() << endl;
    set<productionSet>::iterator k = productions_.begin();
    
    for (int l=0; l<productions_.size(); l++){
        productionSet temp_production_set = *k;
        if(startSymbol_==temp_production_set.get_nonTerminal()){
            fs << temp_production_set.get_nonTerminal();
            break;
        }
        k++;
    }

    k = productions_.begin();

    for (int l=0; l<productions_.size(); l++){
        productionSet temp_production_set = *k;
        if(startSymbol_!=temp_production_set.get_nonTerminal()){
            fs << " " << temp_production_set.get_nonTerminal();
        }
        k++;
    }
    
    fs << endl;

    // PRODUCCIONES
    
    k = productions_.begin();
    
    for (int l=0; l<productions_.size(); l++){
        productionSet temp_production_set = *k;
        if(startSymbol_==temp_production_set.get_nonTerminal()){
            fs << temp_production_set.get_nonTerminal() << " -> ";
            set<string> temp_prod = temp_production_set.get_productions();
            set<string>::iterator m =temp_prod.begin();
            for (int n=0; n<temp_prod.size()-1; n++){
                fs << (*m) << " | ";
                m++;
            }
            fs << (*m) << endl;
            break;
        }
        k++;
    }
    
    k = productions_.begin();
    
    for (int l=0; l<productions_.size(); l++){
        productionSet temp_production_set = *k;
        if(startSymbol_!=temp_production_set.get_nonTerminal()){
            fs << temp_production_set.get_nonTerminal() << " -> ";
            set<string> temp_prod = temp_production_set.get_productions();
            set<string>::iterator m =temp_prod.begin();
            for (int n=0; n<temp_prod.size()-1; n++){
                fs << (*m) << " | ";
                m++;
            }
            fs << (*m) << endl;
        }
        k++;
    }
    fs.close();
}