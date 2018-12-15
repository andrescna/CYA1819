#include "DFA.hpp"

//! Constructor por defecto
DFA::DFA(){}
//! Destructor
DFA::~DFA(){}

///////////////////////////////////////  METODOS DE CLASE DFA ////////////////////////////////////////

//! Leer DFA.
/*!
    Lee un DFA que recibe desde un archivo «filename» y lo almacena en memoria para operar con él.
*/
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
            
            //TE SALTAS EL NUMERO DE TRANSICIONES.
            j+=2;

            //nº de transiciones
            char transition_number = (line[j]);
            int trans_n = transition_number - '0';
            j+=2;
            string temp_state_symbols = "";

            for (; j < line.length();j+=4){
                                
                if (temp_state_symbols.find(line[j]) != temp_state_symbols.npos){
                    cout << endl << "\e[1mERROR\e[0m. Multiples transiciones para el mismo símbolo. " << endl;
                    return (3);
                }
                else {
                    // inserta el símbolo en el alfabeto, si no está
                    if (alphabet_.find(line[j]) == alphabet_.end()) {
                        alphabet_.insert(line[j]);
                    }
                    temp_state_symbols += line[j];
                    temp.add_transition(line[j], line[j+2]);
                }
                // para comprobar que la transición es única por símbolo
                // añade un vector de char donde metas los que has leído
                // y compara a ver. si es igual, return(3)
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
            cout << endl << "-> \e[1mDFA cargado con éxito\e[0m" << endl << endl;
        return(0);
        }
    }

    // ERROR 1: error al abrir archivo
    else 
        cout << endl << "\e[1mERROR\e[0m. Nombre de fichero no encontrado." << endl;
        return (1);

}

//! Mostrar DFA.
/*!
    Muestra por consola el DFA almacenado en memoria.
*/
void DFA::show_DFA(){

    cout << endl << "El DFA cargado es:" << endl << endl;
    
    cout << totalStates_ << endl;
	cout << initialState_ << endl;

    set<state>::iterator i = states_.begin();
    
	for (int j = 0; j < totalStates_; j++){
		
        state temp_state = *i;
        
        // imprime identificador de estado y número de transiciones
        cout << temp_state.get_stateId() << " ";
        temp_state.get_isStateFinal () ? cout << "1 " : cout << "0 "; 
        cout << temp_state.get_transitionNumber(); 

        set<transition> temp_transition_set = temp_state.get_transitionSet();
        set<transition>::iterator k = temp_transition_set.begin();

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
    Calcula si el DFA tiene estados de muerte (que no tienen transiciones salientes).
*/
void DFA::calc_death_states(){

    set<state>::iterator i = states_.begin();
    bool hasDeathStates = false;
    
	// para cada estado comprueba si todas sus transiciones son a sí mismo
    for (int j = 0; j < totalStates_; j++){
		
        state temp_state = *i;

        char stateId = temp_state.get_stateId(); 

        set<transition> temp_transition_set = temp_state.get_transitionSet();
        set<transition>::iterator k = temp_transition_set.begin();
        
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
        cout << "El DFA no tiene estados de muerte" << endl;
    }

    cout << endl;
}

//! Analizar cadena
/*!
    Para una cadena introducida por el usuario muestra el recorrido realizado y si
    acepta o no dicha cadena
*/
int DFA::analyze_word(string word){

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

        set<state>::iterator i = states_.begin();
                
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
    
    }

    // una vez comprobada toda la cadena, busca en el set de estados el estado actual (final al procesarla toda)
    // y comprueba si es de aceptación o no   
    set<state>::iterator i = states_.begin();
                
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

//! Convertir a GR
/*!
    Convierte un DFA en una gramática regular
*/
GR DFA::convert_to_GR(){

    set<productionSet> temp_productions;

    set<state>::iterator i = states_.begin();
    
    for (int j = 0; j < totalStates_; j++){

        state temp_state = *i;

        productionSet aux_pset;
        char aux_symbol;// = temp_state.get_stateId()+16;

        if (initialState_== '0'){
            aux_symbol = temp_state.get_stateId()+16;
        }
        else {
            aux_symbol = temp_state.get_stateId()+17;
        }
        
        
        if (temp_state.get_stateId() == initialState_){
            aux_symbol = 'S';
        }

        aux_pset.set_nonTerminal(aux_symbol);

        if (temp_state.get_isStateFinal()){
            aux_pset.add_production("~");
        }

        // sin esto hace segfaults ¬___¬
        set<transition> temp_transition_set = temp_state.get_transitionSet();
        set<transition>::iterator k = temp_transition_set.begin();

        for(int l = 0; l< temp_state.get_transitionSet().size(); l++){

            transition temp_transition = *k;
            char aux_1 = temp_transition.get_character();
            char aux_2;
            
            if (initialState_== '0'){
                aux_2 = temp_transition.get_next_state()+16;
            }
            else {
                aux_2 = temp_transition.get_next_state()+17;
            }
            
            if (temp_transition.get_next_state()==initialState_){
                aux_2 = 'S';
            }

            string aux_prod = "";

            aux_prod += aux_1; 
            aux_prod += aux_2;

            aux_pset.add_production(aux_prod);

            k++;
        }
        temp_productions.insert(aux_pset);
        i++;
    }
    GR grammar(alphabet_, 'S', temp_productions);
    return grammar;
}