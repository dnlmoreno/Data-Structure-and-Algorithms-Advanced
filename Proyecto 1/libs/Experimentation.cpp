#include "Experimentation.hpp"

Experimentation::Experimentation(/* args */)
{
}

Experimentation::~Experimentation()
{
}
void Experimentation::fill(int n){
    
}
void Experimentation::debugBinaryHeap(){

}
void Experimentation::debugBinomialHeap(){

}
void Experimentation::getInsertionTime(){
      int rep = 10000;
  for(int n = 100000; n <= 1000000; n+=100000){


    clock_t start = clock();

    for(int i = 0; i < rep; ++i){
    }
    // clock lo mide en segundos por lo que hay que convertirlo a milisegundos
    double duracion = (((double)(clock() - start) / CLOCKS_PER_SEC)/rep) * 1000;
    std::cout <<duracion<< '\n';
  }
}
void Experimentation::getMergeTime(){
int rep = 10000;
  int n = 1000001;
  for(int i = 100000; i <= 1000000; i+=100000){
    clock_t start = clock();
    for(int i = 0; i < rep; ++i){
       // busquedaSecuencial(vec[i ],vec);
       // busquedaBinaria(0,vec.size() - 1,vec[i],vec);
       // busquedaGalopante(vec[i],vec);
    }
    // clock lo mide en segundos por lo que hay que convertirlo a milisegundos
    double duracion = (((double)(clock() - start) / CLOCKS_PER_SEC)/rep) * 1000;
    std::cout <<duracion<< '\n';
  }
}