#include "stateSet.hpp"


//! Constructor por defecto
stateSet::stateSet(){}

//! Constructor de copia de set_   
stateSet::stateSet(set<state> subset){
	set_ = subset;
}

//! Constructor con nuevo estado e id (para separar en subconjuntos)
stateSet::stateSet(state newState, char id){
	set_.insert(newState);
	setId_ = id;
}

//! Destructor
stateSet::~stateSet(){}

////////////////////////////////////// METODOS DE CLASE STATESET ////////////////

// SETTERS Y GETTERS

//! Inserta estado en el conjunto
void stateSet::insert_state(state s){
    set_.insert(s);
}

//! Devuelve el conjunto de estados
set<state> stateSet::get_states(){
    return set_;
}

//! Devuelve el identificador
char stateSet::get_id(){
	return setId_;
}

void stateSet::set_id(int id){
	//static_cast<char>(id);
	setId_ = '0' + id;
}

/////////////// OPERATOR OVERLOAD //////////////////////////

//! sobrecarga operador ==
int stateSet::operator==(const stateSet &rhs) const{
	if (this->set_.size()!=rhs.set_.size()) return 0;
	
	set<state>::iterator i = this->set_.begin();
	set<state>::iterator j = rhs.set_.begin();

	for (int k = 0; k< this->set_.size(); k++){

		if ((*i == *j) == 0){ //OJO: Para no tener que sobrecargar != en state 
			return 0;
		}
		i++;
		j++;
	}
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////


// MÉTODOS PARA OPERAR CON STATE SETS

//! Crear nueva partición
/*!
    Utiliza el algoritmo de minimización de estados para obtener el DFA mínimo a partir de un DFA
	Esta función recibe un conjunto PI de estados (conformados por subconjuntos de estados originales) y para
	cada uno de los estados de PI comprueba para cada símbolo del alfabeto si todos los estados
	originales dentro de cada estado de PI transitan al mismo estado de PI. Si no lo hacen se
	divide ese estado de PI en tantos estados de PI nuevos como transiciones a distintos estados
	de PI haya.
*/
vector<stateSet> create_new_partition(vector<stateSet> PI, set<char> alphabet, int index){

	// En cada llamada se realiza una pasada para cada símbolo del alfabeto
	for (set<char>::iterator i = alphabet.begin(); i != alphabet.end(); i++){

		char symbol = *i;

		//para reasignar el id de subconjunto (y poder controlar a dónde transita cada estado)
		for (int i=0; i< PI.size(); i++){
        PI.at(i).set_id(i);
    	}

		//vector<stateSet>::iterator vector_subset_it = PI.begin();
		int jump=0;

		for (int j = 0; j < PI.size();) {
			
			vector<stateSet>::iterator vector_subset_it = PI.begin();
			// si el conjunto tiene tamaño 1 es indivisible, así que lo saltamos
			if ( PI.at(j).get_states().size() != 1){

				set<state> temp_state_set = PI.at(j).get_states();
				set<state>::iterator k = temp_state_set.begin();

				vector<stateSet> new_subset;

				//para cada estado del conjunto
				for (int l =0; l<temp_state_set.size(); l++) { 

					state temp_state = *k;

            		set<transition> temp_transition_set = temp_state.get_transitionSet();
            		set<transition>::iterator m = temp_transition_set.begin();
            
            		for (int n =0; n < temp_state.get_transitionNumber(); n++){

                		transition temp_transition = *m;
                		
						// Para cada transición miramos qué estado de PI contiene el estado original
						// al que transita dicha transición.
						if(temp_transition.get_character() == symbol) {
                    
                    		for (int o = 0; o < PI.size(); o++){

                            	set<state> temp_state_set = PI.at(o).get_states();
                            	set<state>::iterator p = temp_state_set.begin();

                            	for (int q = 0; q < temp_state_set.size(); q++){

                                	state temp_next_state = *p;
                                	if (temp_next_state.get_stateId()==temp_transition.get_next_state()){
                                    
									/*	Se divide el estado de PI en tantos subconjuntos como transiciones a
										estados de PI distintos haya. Usamos el ID de estado como método de
										controlar a qué subconjunto se añade cada estado.
									*/
										if (new_subset.size() == 0){
											new_subset.push_back(stateSet(temp_state,o));	
										}

										else {
											bool inserted = false;
											for (int r=0; r<new_subset.size(); r++) {
												if (new_subset.at(r).get_id() == o) {
													new_subset.at(r).insert_state(temp_state);
													inserted = true;
												}
											}
											if (inserted == false){
												new_subset.push_back(stateSet(temp_state,o));
											}
										}
									o=PI.size();
									n=temp_state.get_transitionNumber();
                                    break;
                                	}
                                p++;
                            	}
                    		}
                		}
                		m++;
					}
					k++;
				}

				/* 	Una vez tenemos dividido el estado de PI en los subconjuntos correspondientes
					lo "sustituimos" en PI eliminando el estado de PI e insertando nuestros nuevos
					subconjuntos, que pasan a ser estados de PI
				*/
				PI.erase(vector_subset_it+jump);

				for (int s=new_subset.size()-1; s>=0; s--) {
					PI.insert(vector_subset_it+jump, new_subset.at(s));
				}
				
				// Y saltamos al siguiente de los estados que no hayamos analizado
				j+=new_subset.size();
				jump+=new_subset.size();
				//for (int it =0; it < new_subset.size(); it++){
				//	vector_subset_it++;
				//}
				
				//vector_subset_it+=new_subset.size();
			}
			else {
				j++;
				//vector_subset_it++;
				jump++;
			}
		}

		cout << "Con el símbolo " << symbol << ":" << endl;
		show_stateSet(PI, index);
		cout << endl;
	}
	return PI;
}

//! Mostrar conjunto de estados
/*!
    Imprime nuestro conjunto de estados(o conjuntos de estados)
*/
void show_stateSet(vector<stateSet> PI, int index){

    cout << "P" << index << " = { ";

    for (int i = 0; i < PI.size(); i++){
		cout << "{";

		set<state> temp_state_set = PI.at(i).get_states();
	    set<state>::iterator j = temp_state_set.begin();
		
		// imprimimos el primer elemento separado por cuestiones de formato
		state temp_state = *j;
		cout << temp_state.get_stateId();
		j++;

		for (int k=0; k < temp_state_set.size()-1; k++){
            state temp_state = *j;
			cout << ", " << temp_state.get_stateId();
			j++;
		} 
		cout << "} ";
	}
	cout << "}" << endl;
}