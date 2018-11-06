// CYA 1718
// Andrés Concepción Afonso

#include "sorted_vector_t.hpp"

#include <climits>
#include <iomanip>

namespace CyA
{

void sorted_vector_t::merge_sort(void)
{
    merge_sort(0, size() - 1);
}

void sorted_vector_t::write(ostream& os) const
{
    const int sz = size();

    os << "< ";
    for(int i = 0; i < sz; i++)
        os << setw(5) << at(i);
    os << "> ";
}


void sorted_vector_t::merge_sort(int l, int r)
{
    static int contador=0;
    
    if (l < r) {
        
        int c = (l + r) / 2;

        merge_sort(l, c);

        merge_sort(c + 1, r);

        merge(l, c, r);
        contador++;
    }
    cout << "el numero de fusiones es: " << contador << endl;

}


////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::create_vector_sentinel(int l, int r, vector<int>& v)
{

}

void sorted_vector_t::merge(int l, int c, int d)
{
    int j=c+1;

    for (int i=l; i<=d;){
        //// Recorremos el vector entero
        if (j<=d){
            //// Si v[i] es menor o igual que v[j], dejamos v[i] igual
            if (at(i)<=at(j)){
                j++;
            }
            //// Si v[i] es mayor que v[j], se intercambian
            else {
                std::swap(at(i),at(j));
                j++;
            }
        }
        /// Si hemos llegado al final de v, aumentamos i y volvemos a escanear v desde su principio
        else {
            i++;
            if (i<=c) {
                j=c+1;
            }
            //Si hemos ordenado ya el subvector izquierdo, i apunta a una posición del subvector derecho
            // por lo que j no puede apuntar a una posición anterior a la de i (los elementos anteriores
            // estarían ya ordenados)
            else {
                j=i;
            }   
        }
    }
}

////////////////////////////////////////////////////////////////////////////

}


ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v)
{
    v.write(os);
    return os;
}
