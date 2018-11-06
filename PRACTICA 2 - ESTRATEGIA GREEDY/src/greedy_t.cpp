// Andrés Concepción Afonso

#include "greedy_t.hpp"

#include "point_t.hpp"

#include <set>


namespace CyA {

//// Programa que nos calcula la ruta más corta para visitar todas las ciudades ////
double greedy_t::NN(vector<point_t>& sequence)
{
    // Creamos un conjunto de puntos para las ciudades que no hemos visitado 
    // (en este momento todas)
    set<point_t> pending;
    
    // Insertamos en dicho conjunto todos las ciudades a visitar
    for(const point_t& p: sky_)
        pending.insert(p);
    
    
    // Inicializamos como última visitada a la ciudad inicial
    /* point_t last = sky_[0]; */
    

        /////////// Modificación 1 (seleccionamos como last al último punto de sky_)
        point_t last = sky_[sky_.size()-1];


        ///////// Modificación 2 (seleccionamos como last al mejor punto de los 10 primeros de sky_
        // con respecto al origen [0,0])

        // Creamos un punto origen [0,0] e inicializamos la distancia del candidato a la
        // máxima posible
        const point_t origin(0,0);
        double candidate_distance = 1414.00;

        // para los 10 primeros miembros de sky_
        for (int i=0; i<10; i++){
            //Calculamos la distancia de cada ciudad al origen 
            double distance_to_origin = sky_[i].distance(origin);
            
            // si es menor que la que teníamos almacenada esta ciudad pasa a ser la nueva last,
            // y la distancia candidata la de dicha ciudad
            if (distance_to_origin < candidate_distance) {
                    last = sky_[i];
                    candidate_distance = distance_to_origin;
            }
        }
       
    //la eliminamos del conjunto de pendientes y la introducimos en el conjunto solución
    pending.erase(last);
    sequence.push_back(last);     
    
    // Al inicio la longitud de la ruta es cero
    double tour_length = 0;
    
    do {
        // seleccionamos la primera ciudad de nuestro conjunto de pendientes y como
        // mejor distancia inicial la que hay entre la última ciudad visitada y la 
        // primera de las pendientes
        point_t best_point    = *pending.begin();
        double  best_distance = last.distance(best_point);  
        
        // Entonces, para nuestro conjunto de ciudades pendientes sin visitar:
        for(const point_t& current: pending) {
            // Calculamos la distancia entre la ciudad actual (nuestra candidata) 
            // y la última visitada
            const double current_distance = last.distance(current);
            // si la distancia actual es mejor que la anterior
            if (current_distance < best_distance) {
                // elegimos como mejor distancia la que acabamos de calcular y como
                // candidata a nuestra mejor ciudad en este paso a la que hemos 
                // probado
                best_distance = current_distance;
                best_point    = current;
            }
        }
        
        // Sumamos a la longitud de nuestro recorrido la mejor (más corta) de las 
        // que hemos obtenido
        tour_length += best_distance;
        
        // Elegimos como última ciudad visitada a la candidata que nos ha dado la 
        // mejor ruta (la más corta)
        last = best_point;
        
        // Por lo tanto la eliminamos de la lista de pendientes y la añadimos al conjunto solución
        pending.erase(last);
        sequence.push_back(last);             

    } while(!pending.empty());
    
    // Cuando hayamos visitado todas las ciudades calculamos la longitud total, que es
    // la que teníamos en la última ciudad visitada
    tour_length += last.distance(sequence[0]);
    
    // Y retornamos el resultado: la distancia "mínima" para recorrer todas las ciudades
    return tour_length;
} 

}