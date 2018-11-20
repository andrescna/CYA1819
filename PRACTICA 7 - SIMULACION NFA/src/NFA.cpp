#include "NFA.hpp"

NFA::NFA(){}

NFA::~NFA(){}

////// Class NFA methods

// OJO SI TIENES QUE METER UN ALFABETO !!!!!
int NFA::read_NFA(string filename) {
    
    ifstream file;
    file.open(filename);

    if (file.is_open()){

        //leemos línea por línea
        string line;
        // asignamos el número de estados y el estado inicial
        getline(file, line);
        totalStates_ = stoi(line);

        getline(file, line);
        if (line.size() > 1){    //comprueba si el estado inicial es único
            return (2);
        }
        initialState_ = line.at(0);

        //ahora para cada estado leemos el conjunto de transiciones
        for (int i = 0; i < totalStates_; i++){

            getline(file, line);

            int j=0;

            char stateId = line[j];
            j+=2;
            char isFinalState = line[j];
            state temp(stateId, isFinalState);
            
            j+=2;

            //nº de transiciones
            char transition_number = (line[j]);
            int trans_n = transition_number - '0';

            j+=2;

            string temp_state_symbols = "";

            for (; j < line.length();j+=4){
                
                //comprueba si ya hemos leído el símbolo en este estado                         OJO QUE SI USAS ALFABETO NECESITAS ESTO. SI NO NO    
                if (temp_state_symbols.find(line[j]) != temp_state_symbols.npos){
                    temp_state_symbols += line[j];
                }
                temp.add_transition(line[j], line[j+2]);
            }
            
            if (temp.get_transitionSet().size() != trans_n) {
                    return (5);
            }

            setStates_.insert(temp);
        }


        // si el número de estados descritos no coincide con los que figuran en el fichero
        if (totalStates_ != setStates_.size()){
            return(4);
        }
        
        else {
            cout << endl;
            cout << "*************************" << endl;
            cout << "* NFA cargado con éxito *" << endl;
            cout << "*************************" << endl;

        return(0);
        }
    }

    // error al abrir archivo
    else 
        return (1);

}

// Esta no debería haber que tocarla
void NFA::show_NFA(){

    cout << endl << "El NFA cargado es:" << endl << endl;
    
    cout << totalStates_ << endl;
	cout << initialState_ << endl;

    set<state>::iterator i = setStates_.begin();
    
	for (int j = 0; j < totalStates_; j++){
		
        state temp_state = *i;
        
        // imprime identificador de estado y número de transiciones
        cout << temp_state.get_stateId() << " ";
        temp_state.get_isStateFinal () ? cout << "1 " : cout << "0 "; 
        cout << temp_state.get_transitionNumber(); 

        // para evitar segfaults al acceder a las transiciones
        set<transition> temp_transition_set = temp_state.get_transitionSet();
        set<transition>::iterator k = temp_transition_set.begin();
        // ¯\_(ツ)_/¯ /////////////////////////////////////////////////////////

        for (int l=0; l < temp_state.get_transitionNumber() ; l++){
            transition temp_transition = *k;
            cout << " " << temp_transition.get_character() << " " << temp_transition.get_next_state();
            k++;
        }
        i++;
        cout << endl;
    }
    cout << endl;
}

// esta no debería hacer falta tocarla////////////////////////////////////////////////////////
void NFA::calc_death_states(){

    set<state>::iterator i = setStates_.begin();
    bool hasDeathStates = false;
    
	// para cada estado comprueba si todas sus transiciones son a sí mismo
    for (int j = 0; j < totalStates_; j++){
		
        state temp_state = *i;

        char stateId = temp_state.get_stateId(); 

        // para evitar segfaults al acceder a las transiciones
        set<transition> temp_transition_set = temp_state.get_transitionSet();
        set<transition>::iterator k = temp_transition_set.begin();
        // ¯\_(ツ)_/¯ /////////////////////////////////////////////////////////
        
        bool isDeathState = true;
        
        // si hay una transición hacia otro estado, no es de muerte
        for (int l=0; l < temp_state.get_transitionNumber() ; l++){
            transition temp_transition = *k;
            if (temp_transition.get_next_state() != stateId) {
            isDeathState = false;
            }
            k++;
        }

        if (isDeathState == true){
            cout << "El estado " << stateId << " es de muerte" << endl;
            hasDeathStates = true;
        }
        i++;
    }

    if (hasDeathStates == false) {
        cout << "El NFA no tiene estados de muerte" << endl;
    }

    cout << endl;
}

                /////////////////////////////////// TO DO ///////

void NFA::calc_important_states(){



}

void NFA::is_DFA(){



}


// ESTA SÍ HAY QUE TOCARLA. MUCHO
int NFA::analyze_word(string word){

    cout << endl;
    cout << "——————————————————" << endl;
    cout << "Cadena de entrada: " << word << endl;
    cout << "——————————————————" << endl << endl;
    cout << "Est. actual\tEntrada\t\tEst. siguiente" << endl;
    
    char actualState = initialState_;
    bool transitionFound;

    for (int j=0; j < word.length(); j++) {
        
        cout << actualState << "\t\t" << word.at(j) << "\t\t";

        transitionFound = false;

        set<state>::iterator i = setStates_.begin();
                
        // busca el estado actual en el set de estados y luego comprueba en las trancisiones del estado
        for (int s = 0; s < totalStates_; s++){
		
            state temp_state = *i;

            char stateId = temp_state.get_stateId();

            if (stateId == actualState) {

                // para evitar segfaults al acceder a las transiciones
                set<transition> temp_transition_set = temp_state.get_transitionSet();
                set<transition>::iterator k = temp_transition_set.begin();
                // ¯\_(ツ)_/¯ /////////////////////////////////////////////////////////

                //busca en las transiciones una que contenga el símbolo buscado
                for (int l=0; l < temp_state.get_transitionNumber() ; l++){
                        
                    transition temp_transition = *k;

                    if (temp_transition.get_character() == word.at(j)) {
                        actualState = temp_transition.get_next_state();
                        transitionFound = true;
                    }
                    else {
                        k++;
                    }
                }
               
                // si no ha encontrado transición, da error. Si la ha encontrado, devuelve siguiente estado
                if (transitionFound == false){
                    cout << endl << endl << "\e[1mERROR\e[0m. Ha introducido un símbolo que no reconoce este NFA" << endl << endl;
                    return (1);
                }
                else {
                    cout << actualState << endl;
                }

                s = totalStates_;
            }        
            else 
                i++;
        }
    
    }

    // una vez comprobada toda la cadena, busca en el set de estados el estado actual (final al procesarla toda)
    // y comprueba si es de aceptación o no   
    set<state>::iterator i = setStates_.begin();
                
    for (int j = 0; j < totalStates_; j++){
		
        state temp_state = *i;

        if (temp_state.get_stateId() == actualState){
            if (temp_state.get_isStateFinal() == true){
                cout << endl << "\e[1mCADENA ACEPTADA\e[0m" << endl << endl;
            }
            else
                cout << endl << "\e[1mCADENA NO ACEPTADA\e[0m" << endl << endl;
        }
        i++;   
    }
    return 0;
}

