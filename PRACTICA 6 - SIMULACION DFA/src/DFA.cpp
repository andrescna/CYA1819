#include "DFA.hpp"

 DFA::DFA(){
 }

 DFA::~DFA(){
}

////// Class DFA methods

int DFA::read_DFA(string filename) {
    
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
            return (1);
        }
        initialState_ = line.at(0);

        //ahora para cada estado leemos el conjunto de transiciones
        for (int i = 0; i < totalStates_; i++){

            getline(file, line);


            // ESTO NO VA A SERVIR (o sí??)
            int j=0;

            char stateId = line[j];
            j+=2;
            char isFinalState = line[j];
            state temp(stateId, isFinalState);
            
            //TE SALTAS EL NUMERO DE TRANSICIONES. ESO SE VE CON UN set.size()
            j+=4;

            // nestado aceptacion [simbolo estadofinal]
            for (; j < line.length();j+=4){
                temp.add_transition(line[j], line[j+2]);
            }
            //cout << "ahora a ver";
            //TIENES QUE SOBRECARGAR OPERADORES
            //aquí haz un insert del estado en el cevtor

            setStates_.insert(temp);
        }
        
        cout << endl;
        cout << "*********************" << endl;
        cout << "DFA cargado con éxito" << endl; // ya está???¿?¿?¿?¿
        cout << "*********************" << endl;

        return(0);
            
        //aquí van cosas
        
    }

    // failed opening file
    else 
        return (1);

}


void DFA::show_DFA(){

    cout << endl << "El DFA cargado es:" << endl << endl;
    
    cout << totalStates_ << endl;
	cout << initialState_ << endl;

    set<state>::iterator i = setStates_.begin();
    
	for (int j = 0; j < totalStates_; j++){
		
        state temp_state = *i;
        
        cout << temp_state.get_stateId() << " ";
        temp_state.get_isStateFinal () ? cout << "1 " : cout << "0 "; 
        cout << temp_state.get_transitionNumber(); 

        // esto es una chapuza pero si no lo haces así tira segfaults como loco
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


void DFA::calc_death_states(){

    set<state>::iterator i = setStates_.begin();
    bool hasDeathStates = false;
    
	for (int j = 0; j < totalStates_; j++){
		
        state temp_state = *i;

        char stateId = temp_state.get_stateId(); 

        // esto es una chapuza pero si no lo haces así tira segfaults como loco
        set<transition> temp_transition_set = temp_state.get_transitionSet();
        set<transition>::iterator k = temp_transition_set.begin();
        // ¯\_(ツ)_/¯ /////////////////////////////////////////////////////////
        
        bool isDeathState = true;

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
        cout << "El DFA no tiene estados de muerte" << endl;
    }

    cout << endl;
}


int DFA::analyze_word(string word){

    cout << endl;
    cout << "——————————————————" << endl;
    cout << "Cadena de entrada: " << word << endl;
    cout << "——————————————————" << endl << endl;
    cout << "Est. actual\tEntrada\t\tEst. siguiente" << endl;
    
    char actualState = initialState_;
    bool transitionFound;
    bool end = false;

    //hasta aquí bien. El problema es el resto xDDD

    for (int j=0; j < word.length(); j++) {
        
        cout << actualState << "\t\t" << word.at(j) << "\t\t";

        transitionFound = false;

        set<state>::iterator i = setStates_.begin();
                
        for (int s = 0; s < totalStates_; s++){
		
            state temp_state = *i;

            char stateId = temp_state.get_stateId();

            if (stateId == actualState) {

                // esto es una chapuza pero si no lo haces así tira segfaults como loco
                set<transition> temp_transition_set = temp_state.get_transitionSet();
                set<transition>::iterator k = temp_transition_set.begin();
                // ¯\_(ツ)_/¯ /////////////////////////////////////////////////////////
        
                for (int l=0; l < temp_state.get_transitionNumber() ; l++){
                        
                    transition temp_transition = *k;

                    if (temp_transition.get_character() == word.at(j)) {
                        //cout << "transicion" << endl;
                        actualState = temp_transition.get_next_state();
                        transitionFound = true;
                        end = true;
                    }
                    else {
                        k++;
                    }
                }
               

                if (transitionFound == false){
                    cout << endl << endl << "\e[1mERROR\e[0m. Ha introducido un símbolo que no reconoce este DFA" << endl << endl;
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
    
    //cout << endl;
    }
           
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

