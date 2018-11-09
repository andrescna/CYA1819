// Standard Template Library example using a class.

#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

// The Set STL template requires overloading operators =, == and <.

#include "elements.h"

void print (set <elements> Cjto){
	for (set<elements>::iterator i = Cjto.begin(); i != Cjto.end(); i++)
	cout << (*i); 
}

int main(){
	const int N = 6;	
	const char* a[N] = {"isomer", "ephemeral", "prosaic", 
                        "nugatory", "artichoke", "serif"};
	const char* b[N] = {"flat", "this", "artichoke",
                        "frigate", "prosaic", "isomer"};
                      
	set <elements> CjtoA;
	set <elements> CjtoB;

    // Inicializamos conjunto A
	cout << "Conjunto A" << endl;
	for (int i=0; i<N;i++){
		elements tmp(a[i]);
		CjtoA.insert(tmp);
	}	
	print(CjtoA);

    // Inicializamos conjunto B
	cout << "Conjunto B" << endl;
	for (int i=0; i<N;i++){
		elements tmp(b[i]);
		CjtoB.insert(tmp);
	}
	print(CjtoB);
	
	cout << "Union: ";
	ostream_iterator< elements > iter( cout, " " );
	set_union(CjtoA.begin(), CjtoA.end(), CjtoB.begin(), CjtoB.end(), iter );
    cout << endl;
    
    cout << "Intersection: ";
	set_intersection(CjtoA.begin(), CjtoA.end(), CjtoB.begin(), CjtoB.end(), iter);    
	cout << endl;

	set <elements> C;  
	set_difference(CjtoA.begin(), CjtoA.end(), CjtoB.begin(), CjtoB.end(),
                   inserter(C, C.begin()));

	cout << "Set C (difference of A and B): ";
	copy(C.begin(), C.end(), iter);
	cout << endl;
}
