#include "NFA.hpp"

//! Constructor por defecto
NFA::NFA(){}
//! Destructor
NFA::~NFA(){}

///////////////////////////////////////  METODOS DE CLASE NFA ////////////////////////////////////////

//! Leer NFA.
/*!
    Lee un NFA que recibe desde un archivo «filename» y lo almacena en memoria para operar con él.
*/
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

        // ERROR 2: más de un estado inicial
        if (line.size() > 1){
            cout << endl << "\e[1mERROR\e[0m. NFA mal formateado: más de un estado inicial" << endl;
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
                cout << endl << "\e[1mERROR\e[0m. NFA mal formateado: Nº de transiciones incorrecto para algún estado." << endl;
                return (5);
            }

            states_.insert(temp);
        }


        // ERROR 4: si el número de estados descritos no coincide con los que figuran en el fichero
        if (totalStates_ != states_.size()){
            cout << endl << "\e[1mERROR\e[0m. NFA mal formateado: Nº de estados incorrecto." << endl;
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
    else {
        cout << endl << "\e[1mERROR\e[0m. Nombre de fichero no encontrado." << endl;
        return (1);
    }

}

//! Mostrar NFA.
/*!
    Muestra por consola el NFA almacenado en memoria.
*/
void NFA::show_NFA(){

    cout << endl << "El NFA cargado es:" << endl << endl;
    
    cout << totalStates_ << endl;
	cout << initialState_ << endl;

    set<state>::iterator i = states_.begin();
    
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

//! Calcular estados de muerte.
/*!
    Calcula si el NFA tiene estados de muerte (que no tienen transiciones salientes).
*/
void NFA::calc_death_states(){

    set<state>::iterator i = states_.begin();
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

//! Calcular estados importantes.
/*!
    Calcula los estados importantes de un NFA. Los estados importantes son los que tienen al menos una
    transición con un símbolo del alfabeto distinto a epsilon O son estados de aceptación.

    Una vez calculados muestra ambos conjuntos (el de importantes y no importantes) o avisa de que 
    todos los estados son importantes.
*/
void NFA::calc_important_states(){

    set<char> important_states;
    set<char> not_important_states;
    set<state>::iterator i = states_.begin();
                
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

//! ¿Es un DFA?.
/*!
    Calcula si el NFA en memoria es un DFA (es decir, que tiene una y solo una transición para cada
    simbolo del alfabeto y además no tiene ninguna epsilon-transición).
*/
bool NFA::is_DFA(){
    
    set<state>::iterator i = states_.begin();
    
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
            return false;
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
                return false;
            }
            else {

                if (temp_alphabet.find(temp_transition.get_character()) != temp_alphabet.end()){
                    temp_alphabet.erase(temp_transition.get_character());
                    k++;
                }            
                // ERROR: si no está el símbolo en el alfabeto es que hay varias transiciones para el mismo => no es DFA
                else {
                    cout << "\e[1mNO ES UN DFA\e[0m. Varias transiciones para un mismo símbolo en un estado" << endl;
                    return false;
                }
            }
        }
        i++;
    }
    return true;
}

//! Analizar cadena
/*!
    Para una cadena introducida por el usuario muestra el conjunto de recorridos posibles que puede
    seguir el NFA con dicha cadena, además de una decisión final. Esta será de aceptación si hay al
    menos un camino para el que la cadena haya sido aceptada, y de no aceptación en otro caso.
*/
void NFA::analyze_word(string word){

    cout << endl;
    cout << "——————————————————" << endl;
    cout << "Cadena de entrada: " << word << endl;
    cout << "——————————————————" << endl << endl;

    int p_n=1;
    int& path_number = p_n;

    bool accepted = false;
    bool& wordAccepted = accepted;

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
			
            set<state>::iterator i = states_.begin();
                
            for (int j = 0; j < totalStates_; j++){
		
                state temp_state = *i;

                if (temp_state.get_stateId() == actualState){
                    if (temp_state.get_isStateFinal() == true){
                        cout << "Camino " << path_number << endl << endl;
                        cout << "Est. actual\tEntrada\t\tEst. siguiente" << endl;
                        cout << path << endl;
                        cout << endl << "\e[1m*** CADENA ACEPTADA ***\e[0m" << endl << endl; 

                        wordAccepted = true;
                    }
                    else {
                        cout << "Camino " << path_number << endl << endl;
                        cout << "Est. actual\tEntrada\t\tEst. siguiente" << endl;
                        cout << path << endl;
                        cout << endl << "\e[1mCADENA NO ACEPTADA\e[0m" << endl << endl;
                        cout << "——————————————————————————————————————" << endl << endl;
                        path_number++;
                    }
                }
                i++;   
            }    
		}

		set<state>::iterator i = states_.begin();
                
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
                        string auxPath = path + actualState + "\t\t~\t\t" + temp_transition.get_next_state() + "\n"; 

				        state_vector.push_back(temp_transition.get_next_state());
				        analyzed_word.push_back(subWord);	
				        path_set.push_back(auxPath);

                    }

                    if (temp_transition.get_character() == subWord[0]) {
                        transitionFound = true;
                        string auxPath = path + actualState + "\t\t" + subWord[0] + "\t\t" + temp_transition.get_next_state() + "\n";

				        state_vector.push_back(temp_transition.get_next_state());
				        analyzed_word.push_back(subWord.substr(1));
				        path_set.push_back(auxPath);
                    }
                    k++; 
                }
               
                // si no encuentra ninguna transición para este símbolo
		        if ((transitionFound == false) && (subWord != "")){
			        cout << "Camino " << path_number << endl << endl;
                    cout << "Est. actual\tEntrada\t\tEst. siguiente" << endl;
                    cout << path << endl;
                    cout << endl << "\e[1mCADENA NO ACEPTADA\e[0m" << endl << endl;
                    path_number++;
		        }
                s = totalStates_;
            }        
            else 
                i++;
        }
    }

    if (wordAccepted){
        cout << endl << "Decisión final:" << endl;
        cout << endl << "***************";
        cout << endl << "\e[1mCADENA ACEPTADA\e[0m"; 
        cout << endl << "***************" << endl;
    }
    else {
        cout << endl << "Decisión final:" << endl;
        cout << endl << "xxxxxxxxxxxxxxxxxxxxxx";
        cout << endl << "\e[1mx CADENA NO ACEPTADA x\e[0m"; 
        cout << endl << "xxxxxxxxxxxxxxxxxxxxxx" << endl;
    }
}


//! Minimizar DFA
/*!
    Utiliza el algoritmo de minimización de estados para obtener el DFA mínimo a partir de un DFA
*/
void NFA::minimize_DFA(){

    vector<stateSet> PI;
    stateSet accepted;
    stateSet notAccepted;

    set<state>::iterator i = states_.begin();

    // Separa dos conjuntos iniciales: aceptación y no aceptación
    for (int j=0; j< totalStates_; j++){

        state temp_state = *i;

        if (temp_state.get_isStateFinal() == true){
            accepted.insert_state(*i);
        }
        else {
            notAccepted.insert_state(*i);
        }
        i++;
    }

    PI.push_back(notAccepted);
    PI.push_back(accepted);

    cout << endl << "Conjunto inicial:"<< endl;
    show_stateSet(PI, 0);
    cout << endl;

    vector<stateSet> PI_aux;
    set<char> temp_alphabet = alphabet_;
    int index = 1;
    
    // Mientras PI se pueda subdividir
    do {
            PI_aux = PI;
            PI = create_new_partition(PI_aux, temp_alphabet, index);
            index++;

    } while (PI != PI_aux);

    cout << "El DFA minimizado tiene " << PI.size() << " estados" << endl << endl; 
    
    // Almacenamos el DFA minimizado en memoria sustituyendo al anterior
    build_DFA(PI);
}


//! Construir DFA
/*!
    Almacena el DFA minimizado en memoria sustituyendo el anterior de acuerdo al resultado de minimize_DFA
*/
void NFA::build_DFA(vector<stateSet> PI){

    states_.clear();
    totalStates_ = PI.size();

    // para cada estado asignamos un identificador correlativo (el nuevo identificador de estado)
    for (int i=0; i< PI.size(); i++){
        PI.at(i).set_id(i);
    }

    ////// ESTADO INICIAL //////////////////////////
    // Buscamos en el conjunto de nuevos estados aquel que contiene al estado inicial del DFA original
    for (int i=0; i< PI.size(); i++){
        
        set<state> temp_state_set = PI.at(i).get_states();
        set<state>::iterator j = temp_state_set.begin();

        for (int k=0; k< temp_state_set.size(); k++){
            
            state temp_state = *j;
            if (temp_state.get_stateId() == initialState_){
                initialState_ = PI.at(i).get_id();
                i = PI.size();
                break;
            }
        }
    }

    // Para cada uno de los nuevos estados de nuestro DFA minimizado
    for (int i = 0; i < PI.size(); i++){
		
		set<state> temp_state_set = PI.at(i).get_states();

        state new_state;
        new_state.set_isStateFinal(false);
        new_state.set_stateId(PI.at(i).get_id());

        //// SI ES ESTADO FINAL ////////////////////////////
        // (alguno de los estados que lo componen es final en el DFA original)
        set<state>::iterator end = temp_state_set.begin();
        for (int z = 0; z< temp_state_set.size(); z++){
            state temp_state = *end;
            if (temp_state.get_isStateFinal()){
                new_state.set_isStateFinal(true);
                break;
            }
            end++;
        }

        /*  Para cada uno de los nuevos estados miramos a qué nuevo estado transita para cada uno
            de los símbolos del alfabeto. Como las transiciones que tenemos hacen referencia a los
            estados originales debemos buscar en qué nuevo estado se encuentra nuesto estado original 
            al que transita. El ID del nuevo estado que lo contenga será el que aparezca en la nueva
            transición. Como suponemos que están reducidos al máximo SOLO SE MIRAN LAS TRANSICIONES
            DEL PRIMER ELEMENTO (el resto deberían transitar a los mismos nuevos estados)
        */
        set<state>::iterator j = temp_state_set.begin();
        
        for (set<char>::iterator k = alphabet_.begin(); k != alphabet_.end(); k++){
            
            char symbol = *k;
            state temp_state = *j;

            set<transition> temp_transition_set = temp_state.get_transitionSet();
            set<transition>::iterator l = temp_transition_set.begin();
            
            for (int m =0; m < temp_state.get_transitionNumber(); m++){

                transition temp_transition = *l;
                if(temp_transition.get_character() == symbol) {
                    
                    // Para cada transición miramos qué nuevo conjunto contiene
                    // el estado original al que transita
                    for (int n = 0; n < PI.size(); n++){

                        set<state> temp_state_set = PI.at(n).get_states();
                        set<state>::iterator o = temp_state_set.begin();

                        for (int p = 0; p < temp_state_set.size(); p++){

                            state temp_state = *o;

                            if (temp_state.get_stateId()==temp_transition.get_next_state()){
                                new_state.add_transition(symbol,PI.at(n).get_id());
                                n=PI.size();
                                break;
                            }
                            o++;
                        }
                    }
                }
                l++;
            }
		}
        // Una vez miradas todas las transiciones insertamos el nuevo estado en nuestro DFA
        states_.insert(new_state); 
	}
}


//! Escribir NFA/DFA a archivo
/*!
    Imprime el NFA cargado en memoria a un fichero de salida, de acuerdo al formato estándar.
    (Básicamente es el de imprimir a consola pero con fs en vez de cout ¬_¬)
    En la implementación actual del programa (práctica 8) esta opción sólo será válida para DFAs
*/
void NFA::write_to_file(string output){
    
    ofstream fs(output, ios::out);
	
    fs << totalStates_ << endl;
    fs << initialState_ << endl;
	
    set<state>::iterator i = states_.begin();
    
	for (int j = 0; j < totalStates_; j++){
		
        state temp_state = *i;
        
        // imprime identificador de estado y número de transiciones
        fs << temp_state.get_stateId() << " ";
        temp_state.get_isStateFinal () ? fs << "1 " : fs << "0 "; 
        fs << temp_state.get_transitionNumber(); 

        // Para poder acceder al set de transiciones sin segfaults
        set<transition> temp_transition_set = temp_state.get_transitionSet();
        set<transition>::iterator k = temp_transition_set.begin();
        // ¯\_(ツ)_/¯ /////////////////////////////////////////////////////////

        for (int l=0; l < temp_state.get_transitionNumber() ; l++){
            transition temp_transition = *k;
            fs << " " << temp_transition.get_character() << " " << temp_transition.get_next_state();
            k++;
        }
        i++;
        fs << endl;
    }
    fs << endl;

    cout << endl <<  "DFA exportado con éxito" << endl;

	fs.close();
}