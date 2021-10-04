#header 
    proyecto 1 
    Autores: 
        Daniel Moreno
        Claudio Rain

* introducción:
         El presente informe tiene por objetivos definir y caracterizar la implementación del algoritmo de compresión Re-pair, uno de los más importantes dentro de la familia de compresión basada en gramáticas. Primero, se determinará  el problema a atacar, para luego presentar dos soluciones, una directa y otra avanzada, presentando sus respectivos detalles de implementación. Finalmente, se presentarán y analizarán los resultados de una serie de experimentos hechos con ambas soluciones.


•Describir las características principales de los tipos de heaps seleccionados.
    Binary Heap:
        es un árbol binario que almacena las entradas en sus nodos y puede
        satisfacer las siguientes propiedades:
            1. Orden: para cada nodo interno v distinto de la raíz, 
                    key(v) >= key(parent(v))
            2. Es un árbol binario completo, esto es:
                1. todos sus niveles, a exepción del último se encuentran llenos.
                2. el árbol se llena de izquierda a derecha
                3. el último nodo

•Describir las decisiones de implementación más importantes.
    Binary Heap:
        
        al ser un árbol de búsqueda balanceado, se implementó el binary heap con un vector, debido
        a la facilidad con que es trabajar con estos.


        

•Plantear varias hipótesis  (al menos 2, máximo 4) sobre el rendimiento de las estructuras  acomparar en escenarios específicos. Por ejemplo, “la estructura X es más rápida en la operaciónOP que la estructura Y cuando los datos  cumplen cierta característica C”, “la estructura Xocupará más espacio que la estructura Y”, etc. 
    posibles hipótesis:



•Diseñar un experimento que permita contrastar cada hipótesis.

•Ejecutar los experimentos y explicar los resultados obtenidos. 

* conclusión:
    A partir de lo desarrollado en este informe, se logró definir y caracterizar ambas soluciones de una manera  eficiente, por lo que los objetivos fueron cumplidos en su totalidad.
	Además, el equipo  ha aprendido bastante sobre el uso de la clase Map, Heaps y listas doblemente enlazadas, para hacer implementaciones mucho más eficientes en tiempo que las demás implementaciones basadas en arreglos…,
	Finalmente, se valora  la realización de este proyecto, comprendiendo que, sea cual sea el futuro profesional de cada integrante, siempre es necesario conocer y analizar el problema para resolverlo de manera adecuada, además de analizar sus respectivos tiempos de ejecución, con los que se familiarizan desde hoy y para siempre.
