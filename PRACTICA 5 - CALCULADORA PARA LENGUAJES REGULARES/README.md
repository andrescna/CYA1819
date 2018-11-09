# Práctica #05: Calculadora para lenguajes regulares

## Objetivo
El objetivo de la práctica es aplicar los conceptos básicos sobre alfabetos, cadenas y lenguajes formales para diseñar una calculadora para lenguajes regulares.

## Descripción
Antes de comenzar a describir la herramienta a desarrollar es importante tener bien claro los tres conceptos básicos introducidos en el primer tema de la asignatura:

* Un **alfabeto** es un *conjunto* no vacío y finito de símbolos.
* Una **cadena** es una *secuencia* finita de símbolos de un determinado alfabeto.
* Un **lenguaje** (formal) es un *conjunto* de cadenas.


## La interfaz

Cuando un usuario ejecute la calculadora para lenguajes regulares, el programa debería mostrar al usuario un menú como el siguiente:
```
1. Inversa
2. Concatenación 
3. Unión 
4. Intersección
5. Diferencia
6. Sublenguajes
7. Igualdad de lenguajes
8. Potencia
9. Cierre de Kleene

>>> Introduzca una opción: 
```


## Especificación de lenguajes: enumeración de cadenas

Hay que tener en cuenta que para las operaciones de inversa, potencia y cierre de Kleene, bastará con que el usuario especifique un único lenguaje, que será el lenguaje sobre el que se llevará a cabo la operación. Sin embargo, para el resto de operaciones será necesario que el usuario especifique los dos lenguajes que intervienen en la operación. La definición de un lenguaje se podría realizar de la forma siguiente:

```
Defina el lenguaje: {abc, bbcc, a, cab}
```

Así se definirían, por ejemplo, las cuatro cadenas que conforman el lenguaje finito anterior. Las cadenas se especifican entre llaves y se separan por comas. Teniendo esto en cuenta, las llaves, los espacios y las comas no deberían usarse como símbolos de los alfabetos sobre los que se forman los lenguajes.

Para especificar el **lenguaje vacío** se podría hacer algo como lo siguiente:

```
Defina el lenguaje: {}
```

Y para especificar la **cadena vacía** se podría utilizar, por ejemplo, el símbolo **&**. Teniendo esto en cuenta, y para evitar confusiones, el símbolo **&** no podrá utilizarse como elemento de los alfabetos que se utilizarán en nuestra calculadora. A modo de ejemplo, lo siguiente serviría para definir al lenguaje que contiene a la cadena vacía:

```
Defina el lenguaje: {&}
```


## Especificación de lenguajes: expresiones regulares

Cuando un lenguaje es finito, es posible definir el lenguaje mediante la enumeración individual de cada una de las cadenas que lo componen, pero cuando un lenguaje regular no es finito, entonces ya no es posible enumerar una a una todas las cadenas que lo conforman. Como alternativa, en estos casos utilizaremos una expresión regular para representar las cadenas que forman parte del lenguaje. Para ello, la notación que se utilizará será la siguiente:

```
Defina el lenguaje: abc | bbcc | a | cab
```

O bien:

```
Defina el lenguaje: (aa)*bc
```

Los paréntesis, el asterisco y la barra vertical se utilizarán para indicar la precedencia en la aplicación de operaciones, para representar el cierre de Kleene y la operación de unión, respectivamente, así que estos símbolos tampoco podrán ser utilizados como símbolos del alfabeto sobre el que se define el lenguaje. Nótese que a diferencia del caso en el que se enumeran las cadenas del lenguaje una a una, aquí no se han usado llaves para englobar a la expresión regular.



## Resultado de las operaciones

Una vez especificado/s el/los lenguaje/s sobre los que realizar la operación, habrá que llevarse a cabo la operación correspondiente y mostrar por pantalla el resultado. Las cadenas que forman parte del lenguaje resultado, deberán mostrarse entre llaves. Cuando el resultado de la operación seleccionada sea un lenguaje infinito, se tratará - en la medida de lo posible - de representarlo mediante una expresión regular. Además, siempre que el resultado de la operación sea un lenguaje infinito se incluirá también la representación del mismo mediante la enumeración de al menos las primeras cadenas del lenguaje, seguidas de tres puntos suspensivos (por lo tanto, los puntos tampoco podrán utilizarse como símbolos de nuestros alfabetos).

Por ejemplo, si se ha seleccionado la operación de concatenación y se han definido los lenguajes:

```
Defina el lenguaje: (a|b)*
Define el lenguaje: c*
```

Entonces como resultado se debería mostrar:

```
Resultado de la concatenación: (a|b)*c*
{&, a, b, ac, bc, aa, ab, ba, bb, aac, ...}
```

Hay que tener en cuenta que, con las pautas que hemos fijado hasta el momento, se están especificando en cada caso las cadenas que componen el lenguaje, pero el usuario no está especificando explícitamente los elementos del alfabeto sobre el que se forman las mismas. Si se quisiera asociar un alfabeto al lenguaje, sería necesario incluir en el mismo todos los símbolos que forman parte de las cadenas. Caso especial sería el del lenguaje vacío y el del lenguaje que contiene a la cadena vacía. En este sentido, hay que recordar que un alfabeto es un conjunto no vacío.

## Notas de implementación
Al igual que en la práctica anterior, en esta práctica se prestará especial atención a la definición de clases y al diseño orientado a objetos que se plantee para la implementación de la calculadora.

Se valorará la implementación de conjuntos utilizando el contenedor set de la STL y del uso del constructor de proyectos Make para la compilación de la práctica.