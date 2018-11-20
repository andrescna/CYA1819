# Práctica #04: Simulación de autómatas finitos no deterministas

## Objetivo

Esta práctica consistirá en la realización de un programa escrito en C++ que lea desde un fichero las especificaciones de un autómata finito no determinista (NFA) y, a continuación, simule el comportamiento del autómata para una cadena que se dé como entrada. Se puede considerar un NFA como una modificación de un DFA en el que se permiten cero, una o varias transiciones desde un estado con un símbolo del alfabeto de entrada. Además, otra diferencia de los NFAs con respecto a los DFAs es que los NFAs pueden tener transiciones vacías (transiciones etiquetadas con la cadena vacía), permitiendo al autómata transitar de un estado a otro sin necesidad de entrada, esto es, sin consumir símbolos de la cadena de entrada. El no determinismo viene dado porque el autómata puede transitar con una misma entrada hacia un conjunto de diferentes estados. Este conjunto de estados podría incluso ser vacío.

## Fichero para la definición autómatas finitos no determinista

Un autómata finito no determinista (NFA) vendrá definido en un fichero de texto con extensión ***.nfa***. Un fichero ***.nfa*** deberá tener el siguiente formato:

* Línea 1: Número total de estados del NFA
* Línea 2: Estado de arranque del NFA

A continuación vendrá una línea para cada uno de los estados. Cada línea contendrá los siguientes números separados entre sí por espacios en blanco:

  * Número identificador del estado. Los estados del autómata se representarán mediante números enteros sin signo. La numeración de los estados corresponderá a los primeros números naturales comenzando por 0.
  * Un 1 si se trata de un estado de aceptación y un 0 si se trata de un estado de no aceptación.
  * Número de transiciones que posee el estado.

A continuación, para cada una de las transiciones, y separados por espacios en blanco, se detallará la información siguiente:
   * Símbolo de entrada necesario para que se produzca la transición. Para representar la cadena vacía (el no consumir símbolo de la entrada) se utilizará el carácter ~ (código ASCII 126).
   * Estado destino de la transición.


A modo de ejemplo, se muestra un NFA junto con la definición del mismo especificada mediante un fichero .nfa

![Ejemplo de NFA](/doc/NFA_sim.jpg)

El programa deberá detectar que no haya ningún error en la definición del autómata. Esto es, habría que analizar que se cumplen las siguientes condiciones:

* Existe uno y sólo un estado inicial para el autómata.
* Hay una línea en el fichero por cada uno de los estados que tiene el autómata. Para aquellos estados que no tengan transiciones salientes, deberemos indicar, en la línea correspondiente del fichero, que el estado en cuestión tiene cero transiciones.

## Funcionamiento general del programa

El programa principal debería ofrecer al usuario las siguientes opciones:

* **Leer NFA:** al seleccionar esta opción se deberá solicitar al usuario que introduzca el nombre del fichero donde se encuentra la especificación del autómata. Tras la inicialización del NFA habrá que notificar al usuario si se produce algún error en la creación del automáta.
* **Mostrar NFA:** al seleccionar esta opción se mostrará por pantalla el autómata actualmente definido (previamente leído de fichero) en nuestro programa. Para mostrar el autómata por pantalla se seguirá el formato establecido para los ficheros ***.nfa***.
* **Identificar estados de muerte:** al seleccionar esta opción se deberá mostrar por pantalla si el autómata previamente definido tiene estados de muerte y si es así, habrá que indicar cuáles son los identificadores de dichos estados de muerte.
* **Identificar estados importantes:** al seleccionar esta opción se deberá mostrar por pantalla el conjunto de estados importantes y el conjunto de estados no importantes del NFA. Hay que recordar que en un NFA decimos que un estado es importante si tiene al menos una transición saliente etiquetada con uno de los símbolos del alfabeto, o bien, si es un estado de aceptación. Es decir, los estados no importantes serán aquellos que no son de aceptación y sólo tienen transiciones salientes etiquetadas con epsilon.
* **Es DFA:** comprobar si el autómata finito cargado desde fichero es un DFA o no. Tener en cuenta que los DFAs tienen una y sola una transición, desde cada estado, para cada uno de los símbolos del alfabeto. Hay que tener en cuenta que aunque el autómata finito leído desde fichero sea un DFA, se podrán aplicar el resto de opciones del menú de la misma forma que si se hubiera tratado de un NFA que no es DFA.
* **Analizar cadena:** al seleccionar esta opción se deberá solicitar al usuario que introduzca una cadena. Para la cadena indicada por el usuario se deberá determinar si es aceptada o no por el autómata actualmente definido. Al igual que ocurre con las opciones anteriores, esta opción tampoco se podrá ejecutar si no se ha inicializado previamente un autómata. El formato de la traza a mostrar por pantalla será el siguiente: 

<pre>Cadena de entrada: ___________<br><br>Camino 1<br>Estado actual    Entrada    Siguiente estado
X                Y          Z
X                Y          Z
X                Y          Z
Cadena de entrada ACEPTADA / NO ACEPTADA<br><br>Camino 2 <br>Estado actual    Entrada    Siguiente estado<br>X                Y          Z<br>X                Y          Z<br>X                Y          Z<br>Cadena de entrada ACEPTADA / NO ACEPTADA<br><br>...<br><br>Camino N<br>Estado actual    Entrada    Siguiente estado<br>X                Y          Z<br>X                Y          Z<br>X                Y          Z<br>Cadena de entrada ACEPTADA / NO ACEPTADA<br><br>Decisión final:<br>Cadena de entrada ACEPTADA / NO ACEPTADA<br></pre>

Tal y como se indica en las líneas anteriores, en primer lugar se deberá mostrar la cadena de entrada. A continuación, y teniendo en cuenta que se trata de NFAs, la traza deberá recoger todos los posibles caminos que se podrían seguir para aceptar o rechazar la cadena de entrada. Para cada uno de los posibles caminos, se indicará cómo va transitando de un estado a otro el autómata según va leyendo la cadena de entrada, indicando en cada caso si por el camino en cuestión se acepta o no la cadena. Finalmente, se deberá indicar la decisión final del autómata mostrando el mensaje ***“Cadena de entrada ACEPTADA”*** si la cadena de entrada es aceptada por el autómata o el mensaje ***“Cadena de entrada NO ACEPTADA”*** si la cadena de entrada no es aceptada por el autómata. Cabe destacar que, desde que se encuentre un camino que acepte la cadena de entrada analizada, la decisión final del NFA será la de "aceptar de la cadena de entrada".

## Detalles de implementación

* Para la implementación de esta práctica es conveniente partir del código desarrollado en la práctica anterior para la simulación de autómatas finitos deterministas.
* Se deberá definir una clase "Estado" que agrupe las características correspondientes a los estados de un autómata y las funcionalidades asociadas a los mismos.
* Se deberá definir una clase "NFA" que implemente las características de los autómatas finitos no deterministas.
* Se requerirá el uso de [Makefiles](https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile) para compilar los códigos.
* Documentación: se requerirá un mínimo de documentación para los códigos desarrollados, por lo menos documentar las cabeceras de las clases y los métodos más importantes. Vean referencias en estos Tips para documentar códigos utilizando [Doxygen](http://www.stack.nl/~dimitri/doxygen/)