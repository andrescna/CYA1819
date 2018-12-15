# Práctica #09: Gramática regular a partir de DFA

## Objetivo

El objetivo de esta práctica consiste en la realización de un programa en C++ que lea desde un fichero la especificación de un autómata finito determinista y obtenga a partir de él una gramática regular que genere el lenguaje reconocido por el autómata.

## Gramática regular

Una gramática regular es una 4-tupla G ≡ (Σ, V, S, P) donde:

* Σ es el conjunto de símbolos terminales o alfabeto de la gramática.
* V es el conjunto de símbolos no terminales.
* S es un símbolo no terminal que se llama símbolo de arranque o axioma de la gramática (S ∈ V ).
* P es una colección de reglas de sustitución denominadas producciones, tal que:
  * Todas las producciones son regulares por la derecha:
                  *A → uB | v*    (tal que A, B ∈ V y u, v ∈ Σ*)
  * O, todas las producciones son regulares por la izquierda:
                  *A → Bu | v*     (tal que A, B ∈ V y u, v ∈ Σ*)

Se dice que una gramática es lineal por la derecha si todas sus producciones son regulares por la derecha. De forma análoga, se dice que una  gramática es lineal por la izquierda si todas sus producciones son regulares por la izquierda.

Teniendo esto en cuenta diremos que una gramática es regular si es lineal por la derecha o lineal por la izquierda.

## Gramática regular a partir de un DFA

Sea *L* un lenguaje regular, entonces existe un DFA *M ≡ (Σ,Q, s, F, δ)*, tal que *L = L(M)*. Además, si *L* es regular también sabemos que existe una gramática regular G ≡ (Σ ', V, S, P) tal que L(G) = L(M).

Dicha gramática regular G se puede definir como: 
 
```
Σ′ = Σ  
V = Q  
S = s  
P = {q → ap | δ(q, a) = p} ∪ {q → ε | q ∈ F}
```

## Ficheros para la especificación de gramáticas

Los ficheros de texto que describen gramáticas regulares o independientes del contexto tendrán la extensión .grammar y la siguiente estructura:

* Línea 1: número total de símbolos terminales que posee la gramática.
* Línea 2: lista de todos los símbolos terminales de la gramática, separados por espacios en blanco. Cada terminal se representa mediante un caracter ASCII.
* Línea 3: número total de símbolos no terminales que posee la gramática.
* Línea 4: lista de todos los símbolos no terminales de la gramática, separados por espacios en blanco. Cada símbolo no terminal vendrá representado también mediante un caracter ASCII, preferiblemente letras mayúsculas de nuestro abecedario. Se tomará como símbolo de arranque de la gramática aquel símbolo no terminal que aparezca primero en esta lista.
* De la línea 5 en adelante el fichero tendrá una línea para cada uno de los símbolos no terminales de la gramática. En cada línea se especificarán las reglas de producción de un determinado símbolo no terminal. Cada línea tendrá el formato siguiente:
  * Caracter correspondiente al no terminal.
  * Flecha '->' (caracteres menos y mayor)
  * Reglas de producción para el no terminal en cuestión. Cada regla de producción estará formada por una sucesión de caracteres correspondientes a símbolos terminales o no terminales, o el caracter ~ (código ASCII 126) para la cadena vacía. Las diferentes alternativas de producciones para un mismo símbolo no terminal vendrán dadas en una misma línea separadas entre sí por el símbolo '|' (barra vertical).
  
A modo de ejemplo, un fichero para la descripción de una gramática regular (y también independiente del contexto) sería el siguiente:

```
2  
0 1  
3  
S A B  
S -> 0A | 1S | ~  
A -> 0B | 1S | ~  
B -> 0B | 1B
```

## Funcionamiento general del programa

El programa principal recibirá mediante la línea de comandos dos argumentos:

* Nombre del fichero *.dfa* donde vendrá dada la especificación del autómata finito determinista a partir del cual se desea construir la gramática regular.
* Nombre del fichero *.grammar* donde se almacenará la especificación de la gramática regular obtenida tras aplicar el proceso de construcción de la gramática a partir del DFA.

El programa deberá funcionar de la manera siguiente:

1) En primer lugar, se deberá crear un objeto **DFA** a partir de la especificación del autómata finito dado en el fichero *.dfa* correspondiente. Al construir el DFA se deberá verificar que el fichero .dfa dado como entrada realmente especifica un autómata finito determinista.
2) A continuación, se aplicará el proceso descrito anteriormente para construir una gramática regular a partir del DFA cargado desde fichero. Para almacenar la gramática regular resultante se creará un objeto de tipo GR (gramática regular).
3) Finalmente, la gramática regular obtenida tras este proceso se exportará al fichero *.grammar* especificado como fichero de salida mediante la línea de comandos.
4) No es necesario que el programa principal muestre al usuario un menú por pantalla. De hecho, no hace falta mostrar los resultados por pantalla pues lo que se solicita es que la gramática obtenida se almacene en un fichero .grammar.

## Detalles de implementación

* Se deberá crear una clase **GR** para representar a una gramática regular. La clase deberá tener al menos métodos que permitan inicializar desde un fichero de entrada y exportar a un fichero de salida.
* Se requerirá el uso de [Makefiles](http://stackoverflow.com/questions/2481269/how-to-make-simple-c-makefile) para compilar los códigos.
* Línea de comandos: el nombre del fichero de entrada (con la especificación del DFA) y el nombre del fichero de salida (con la gramática regular obtenida) se pasarán al programa por línea de comandos.
* Documentación: se requerirá un mínimo de documentación para los códigos desarrollados, por lo menos documentar las cabeceras de las clases y los métodos más importantes. Vean referencias en estos [Tips para documentar códigos] utilizando [Doxygen](http://www.doxygen.nl/index.html)

**NOTA:** ![gr2flap.py](doc/gr2jflap.py) es un script de python para convertir el formato de gramática definido en la práctica al formato [JFLAP](http://www.jflap.org)
