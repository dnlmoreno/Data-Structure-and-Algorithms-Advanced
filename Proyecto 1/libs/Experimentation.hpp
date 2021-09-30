#pragma once

#include "Experimentation.hpp"
#include "BinaryHeap.hpp"
#include "BinomialHeap.hpp"
#include <time.h>
class Experimentation{

private:
    void fillUnordered(vi&,int,int);
    void fillAscending(vi&,int,int);
    // con from = 7 y to = 10 sería 3 2 1
    void fillDescending(vi&,int,int);
    void fillEqual(vi&,int,int);
    
    int getRand(int,int);
public:
/*
opciones operaciones:
    1. búsquedas: (retornar el top)
        1. siempre será lo mismo independiente de la entrada
    2. insertar:
        1. lista ascendente
        2. lista descendente
        3. lista desordenada(promedio)
    3. merge:
        1. merge de un árbol con elementos mayores que otro y viseversa
        2. merge de un árbol con elementos similares
        3. merge de un árbol con elementos aleatorios con uno que tenga elementos iguales (mucho chamullo xd)
*/
    Experimentation(/* args */);
    ~Experimentation();
    
    void getInsertionTime();
    void getMergeTime();
    void getSearchTime();

    void debugBinaryHeap();
    void debugBinomialHeap();
};
