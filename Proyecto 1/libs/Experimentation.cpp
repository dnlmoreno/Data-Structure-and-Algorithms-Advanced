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
	BinaryHeap* bh = new BinaryHeap();

	bh->push(1);
	bh->push(3);
	bh->push(5);
	bh->push(6);
	bh->push(1);
	bh->printBinaryHeap();


}
void Experimentation::debugBinomialHeap(){
  	cout << "Hola Mundo!" << endl;
	BinomialHeap binomial_h;
	BinomialHeap binomial_h2;
	Nodo* H = NULL;
	Nodo* H1 = NULL;
	Nodo* H2 = NULL;
	Nodo* W = NULL;

	//cout << "El binomial esta en la posicion: " << binomial_h.getHeap() << endl;
	//cout << "El binomial esta en la posicion: " << &binomial_h << endl;

	binomial_h.insert(5);
	binomial_h.insert(8);
  /*	binomial_h.insert(10);
	binomial_h.insert(15);
	binomial_h.insert(16);
	binomial_h.insert(17);
	binomial_h.insert(19);


	binomial_h2.insert(0);
	binomial_h2.insert(1);
	binomial_h2.insert(7);
	binomial_h2.insert(26);
	binomial_h2.insert(30); */

	H1 = binomial_h.getHeap();
	H2 = binomial_h2.getHeap();


	//H = binomial_h.union_BH(H1, H2);

	//H = binomial_h.getHeap();

	// binomial_h.Display(H);

	// H = binomial_h.search_Min();

	// cout << "Raiz minima: " << H->info << endl;
	//cout << endl;
	
	// binomial_h.PrintBinomialHeap();

	// cout << "\n#############################" << endl;

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