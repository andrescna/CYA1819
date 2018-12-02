#include "NFA.hpp"

NFA::NFA(){}

NFA::~NFA(){}

////// Class NFA methods

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

            for (; j < line.length();j+=4){
                
                // inserta el símbolo en el alfabeto, si no está
                if (alphabet_.find(line[j]) == alphabet_.end()) 
                    alphabet_.insert(line[j]);

                temp.add_transition(line[j], line[j+2]);
            }
            
            // ERROR 5: nº de transiciones erróneo
            if (temp.get_transitionSet().size() != trans_n) {
                    return (5);
            }

            setStates_.insert(temp);
        }


        // ERROR 4: si el número de estados descritos no coincide con los que figuran en el fichero
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

    // ERROR 1: error al abrir archivo
    else 
        return (1);

}

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

void NFA::calc_important_states(){

    set<char> important_states;
    set<char> not_important_states;
    set<state>::iterator i = setStates_.begin();
                
    // busca el estado actual en el set de estados y luego comprueba en las trancisiones del estado
    for (int s = 0; s < totalStates_; s++){
        
        state temp_state = *i;

        char stateId = temp_state.get_stateId();

        bool importantState = false;

        // para evitar segfaults al acceder a las transiciones
        set<transition> temp_transition_set = temp_state.get_transitionSet();
        set<transition>::iterator k = temp_transition_set.begin();
        // ¯\_(ツ)_/¯ /////////////////////////////////////////////////////////

        // Si el estado es final, es importante
        if (temp_state.get_isStateFinal() == true){
            importantState = true;
        }
        // si no es final, es importante si tiene alguna transición que no sea epsilon (~)
        else {
            for (int l=0; l < temp_state.get_transitionNumber() ; l++){
                        
                transition temp_transition = *k;

                if (temp_transition.get_character() != '~') {
                    importantState = true;
                    l=temp_state.get_transitionNumber();
                }
                else {
                    k++;
                }
            }
        }      
        
        // Metemos cada estado en el conjunto correspondiente
        if (importantState == true){
            important_states.insert(stateId);
        }
        else {
            not_important_states.insert(stateId);
        }
        i++;
    }

    if (not_important_states.size() == 0)
        cout << "Todos los estados son importantes" << endl;
    
    else {
        
        cout << "El automata tiene " << important_states.size() << " estado(s) importantes y " << not_important_states.size() << " estado(s) no importantes" << endl << endl; 
        cout << "El conjunto de estados importantes es: " << endl << "{";

        for (set<char>::iterator i = important_states.begin(); i != important_states.end(); i++) {
            cout << " " << *i;
        }

        cout << " }" << endl << endl << "El conjunto de estados no importantes es: "<< endl << "{";

        for (set<char>::iterator j = not_important_states.begin(); j != not_important_states.end(); j++) {
            cout << " " << *j;
        }
        cout << " }" << endl;
    }
}

void NFA::is_DFA(){
    
    set<state>::iterator i = setStates_.begin();
    
    // se elimina epsilon del alfabeto "temporal" para poder dar el error de que solo hay alguna epsilon-transición
    set<char> alphabet_noepsilon = alphabet_;
    if (alphabet_noepsilon.find('~') != alphabet_noepsilon.end())
        alphabet_noepsilon.erase('~');
     
    // busca el estado actual en el set de estados y luego comprueba en las transiciones del estado
    for (int s = 0; s < totalStates_; s++){
        
        state temp_state = *i;
        set<char>temp_alphabet = alphabet_noepsilon;
        
        //ERROR: si el estado tiene más/menos transiciones que símbolos del alfabeto no es un DFA
        if (temp_alphabet.size() != temp_state.get_transitionNumber()){
            cout << "\e[1mNO ES UN DFA\e[0m. Nº de transiciones inadecuado en alguno de los estados." << endl;
            return;
        }

        // para evitar segfaults al acceder a las transiciones
        set<transition> temp_transition_set = temp_state.get_transitionSet();
        set<transition>::iterator k = temp_transition_set.begin();

        // para cada estado hay que mirar el conjunto de transiciones y ver que tiene una y solo una para cada símbolo
        for (int l=0; l < temp_state.get_transitionNumber() ; l++){
                        
            transition temp_transition = *k;

            // ERROR: si tiene una transición con epsilon, no es un DFA
            if (temp_transition.get_character() == '~'){
                cout << "\e[1mNO ES UN DFA\e[0m. Tiene al menos una epsilon-transición" << endl;
                return;
            }
            else {

                if (temp_alphabet.find(temp_transition.get_character()) != temp_alphabet.end()){
                    temp_alphabet.erase(temp_transition.get_character());
                    k++;
                }            
                // ERROR: si no está el símbolo en el alfabeto es que hay varias transiciones para el mismo => no es DFA
                else {
                    cout << "\e[1mNO ES UN DFA\e[0m. Varias transiciones para un mismo símbolo en un estado" << endl;
                    return;
                }
            }
        }
        i++;
    }
    cout << "El automata cargado \e[1mES UN DFA\e[0m" << endl;
    return;
}


void NFA::analyze_word(string word){

    cout << endl;
    cout << "——————————————————" << endl;
    cout << "Cadena de entrada: " << word << endl;
    cout << "——————————————————" << endl << endl;

    int rec_num=1;
    int& recorrido_number = rec_num;

    vector<char> state_vector;
	vector<string> analyzed_word;
	vector<string> path_set;

	state_vector.push_back(initialState_);
	analyzed_word.push_back(word);
	path_set.push_back("");

	bool transitionFound;

	while (state_vector.size() > 0){
		
        char actualState = state_vector.at(state_vector.size() - 1);
		string subWord = analyzed_word.at(analyzed_word.size() - 1);
		string path = path_set.at(path_set.size() - 1);

		state_vector.pop_back();
		analyzed_word.pop_back();
		path_set.pop_back();
		
        //si ha acabado de procesar la cadena
		if (subWord == ""){
			
            set<state>::iterator i = setStates_.begin();
                
            for (int j = 0; j < totalStates_; j++){
		
                state temp_state = *i;

                if (temp_state.get_stateId() == actualState){
                    if (temp_state.get_isStateFinal() == true){
                        cout << "Recorrido " << recorrido_number << endl << endl;
                        cout << "Est. actual\tEntrada\t\tEst. siguiente" << endl;
                        cout << path << endl;
                        cout << endl << "***************";
                        cout << endl << "\e[1mCADENA ACEPTADA\e[0m"; 
                        cout << endl << "***************" << endl;
                        return;
                    }
                    else {
                        cout << "Recorrido " << recorrido_number << endl << endl;
                        cout << "Est. actual\tEntrada\t\tEst. siguiente" << endl;
                        cout << path << endl;
                        cout << endl << "\e[1mCADENA NO ACEPTADA\e[0m" << endl << endl;
                        cout << "——————————————————————————————————————" << endl << endl;
                        recorrido_number++;
                    }
                }
                i++;   
            }    
		}

		set<state>::iterator i = setStates_.begin();
                
        // busca el estado actual en el set de estados y luego comprueba en las transiciones del estado
        for (int s = 0; s < totalStates_; s++){
		
            state temp_state = *i;

            char stateId = temp_state.get_stateId();

            if (stateId == actualState) {

                transitionFound = false;
                
                // para evitar segfaults al acceder a las transiciones
                set<transition> temp_transition_set = temp_state.get_transitionSet();
                set<transition>::iterator k = temp_transition_set.begin();
                // ¯\_(ツ)_/¯ /////////////////////////////////////////////////////////

                //busca en las transiciones una que contenga el símbolo buscado
                for (int l=0; l < temp_state.get_transitionNumber() ; l++){
                        
                    transition temp_transition = *k;

                    if (temp_transition.get_character() == '~') {
                        transitionFound = true;
                        string recorridoAux = path + actualState + "\t\t~\t\t" + temp_transition.get_next_state() + "\n"; 

				        state_vector.push_back(temp_transition.get_next_state());
				        analyzed_word.push_back(subWord);	
				        path_set.push_back(recorridoAux);

                    }

                    if (temp_transition.get_character() == subWord[0]) {
                        transitionFound = true;
                        string recorridoAux = path + actualState + "\t\t" + subWord[0] + "\t\t" + temp_transition.get_next_state() + "\n";

				        state_vector.push_back(temp_transition.get_next_state());
				        analyzed_word.push_back(subWord.substr(1));
				        path_set.push_back(recorridoAux);
                    }
                    k++; 
                }
               
                // si no encuentra ninguna transición para este símbolo ¿¿??
		        if ((transitionFound == false) && (subWord != "")){
			        cout << "Recorrido " << recorrido_number << endl << endl;
                    cout << "Est. actual\tEntrada\t\tEst. siguiente" << endl;
                    cout << path << endl;
                    cout << endl << "\e[1mERROR\e[0m. Ha introducido un símbolo que no reconoce este NFA" << endl;
                    cout << endl << "\e[1mCADENA NO ACEPTADA\e[0m" << endl << endl;
			        return;
                    recorrido_number++;
		        }
                s = totalStates_;
            }        
            else 
                i++;
        }
    }
}
