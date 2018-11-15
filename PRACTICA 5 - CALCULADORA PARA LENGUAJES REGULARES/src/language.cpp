#include<iterator>
#include<iostream>

#include "language.hpp"

using namespace std;


language::language(){
       
       alphabet alphabet_;
}


alphabet language::get_alphabet(){

        return alphabet_;
}

set<word> language::get_language_elements(){
        return words_;

}



void language::add_alphabet_symbol(){




}

void language::add_word(){


}


////// Parses a string to extract a language and its corresponding alphabet

language parse_language (string userInput, bool &syntaxError){

        cout << "hola\n";
        language parsedLanguage;

        alphabet alfabeto;
        set<word> cadenas;
        
        char readChar;
        word tempWord;
        bool stringProcessed = false;
  
        for (string::iterator i = userInput.begin(); i != userInput.end() /*&& stringProcessed==false*/; i++){
                       
                if (*i != ' '){                        
                // si leemos {
                        if (*i== '{'){
                                if (*i++ == '}'){
                                        //LENGUAJE VACÍO
                                        stringProcessed = true;
                                }
                        }
                                // si hemos llegado al final }
                                if (*i == '}'){
                                    
                                    cout << "llegué\n";
                                    stringProcessed = true;   
                                }
                                // si leemos epsilon
                                if (*i == '&'){
                                        //readChar = "";
                                        cout << "VACIO\n";
                                        //meter en el alfabeto
                                        //meter en el lenguaje
                                        //suponemos que es una coma (?)
                                }
                                ////// EN OTRO CASO si leemos una cadena
                                else if (*i != '}'){
                                        if (*i == ','){
                                                parsedLanguage.get_language_elements().insert(tempWord);
                                                tempWord.clear_word();
                                                //metemos word en el lenguaje
                                        }
                                        // para cualquier otra cosa
                                        else {
                                                readChar = *i;
                                                word tempChar(&readChar);
                                                bool test = parsedLanguage.get_alphabet().is_symbol_in_alphabet(tempChar);

                                                        if ( test == false){
                                                                bool test2 = parsedLanguage.get_alphabet().insert_symbol(tempChar).second;
                                                                cout << "el test ha dado" << parsedLanguage.get_alphabet().insert_symbol(tempChar).second << endl;
                                                        }
                                                alfabeto.insert_symbol(tempChar);
                                                //vemos si está en el alfabeto
                                                //si no está lo metemos
                                                tempWord.add_character(tempChar); //añadimos *i a la word
                                        }
                                }
                        }
        }


        std::cout << "parsed" << endl;

        /*for(set<word>::iterator j = parsedLanguage.get_alphabet().get_symbols().begin(); j != parsedLanguage.get_alphabet().get_symbols().end();j++){

                word tempo(*j);
                cout << (*j) << endl;
                cout << "ihavenoidea\n";
        }*/


        cout << "pls work\n" << endl;
        return parsedLanguage;

}


/*



                        //checks for the first {
                        while (*i != '{' && i != userInput.end()){
                                i++;
                        }
                
                        //first { found
                        if (*i == '{'){
                                i++;
                                if (*i == '}'){
                                        //createemptylanguage AND STOP
                                        stringProcessed=true;
                                }
                                // FOR A NOT EMPTY LANGUAGE
                                else {
                                        while (*i == ' ' && i != userInput.end()){
                                                i++;
                                        }

                                        while (*i != '}' && i != userInput.end()){
                                                                                                                
                                                while (*i == ' ' && i != userInput.end()){
                                                        i++;
                                                }

                                                word newWord;

                                                while (*i != ',' && i != userInput.end()){ //se puede meter la list aquí también
                                                        
                                                        //si el symbolo no está en el alfabeto
                                                        char readChar = *i;
                                                        word characterRead(&readChar);
                                                        //sielsymbololeídonoestáenelealfabetolometemos

                                                        bool test = parsedLanguage.get_alphabet().is_symbol_in_alphabet(characterRead);

                                                        if ( test == false){
                                                                parsedLanguage.get_alphabet().insert_symbol(characterRead);
                                                        }
                                                        newWord.add_character(characterRead);   //FUNCIONA
                                                        i++;
                                                      //  newWord.add_character(characterRead);
                                                }
                                                
                                                //añadimos la word al lenguaje  

                                                parsedLanguage.get_language_elements().insert(newWord); 
                                                cout << "palabraescrita" << endl;
                                                                                             
                                                i++;
                                                }




                                        }
                                        cout << "leída entera" << endl;
                                        stringProcessed = true;

                                }
                        }
                        
                }

        return parsedLanguage;
}              

 

        /*
        un bucle que lee de principio a fin la cadena

        en cuanto encuentra el { empieza a 
                    {
                    - leer secuencialmente hasta la siguiente coma
                        *si el siguiente caracter es } crea LENGUAJE VACIO
                    - lee el caracter y si no está, lo mete en el alfabeto
                    cuando encuentra coma
                            mete la string como word en el set words_
                    sigue leyendo y salta al siguiente caracter que no sea un espacio
                    y hace loop
                    hasta que encuentra }
        sale


        */

language::~language(){

        alphabet_.~alphabet();

}