#include <iostream>
#include "libs/BinomialHeap.hpp"

using namespace std;

int main(int argc, char* argv[]){
	cout << "Hola Mundo!" << endl;
	BinomialHeap binomial_h;
	Nodo* H = NULL;
	Nodo* W = NULL;

	//cout << "El binomial esta en la posicion: " << binomial_h.getHeap() << endl;
	//cout << "El binomial esta en la posicion: " << &binomial_h << endl;

	binomial_h.insert(5);
	binomial_h.insert(8);
	binomial_h.insert(10);
	binomial_h.insert(15);
	binomial_h.insert(16);
	binomial_h.insert(17);
	binomial_h.insert(19);
	binomial_h.insert(1);
	binomial_h.insert(7);

	H = binomial_h.getHeap();
	binomial_h.Display(H);

	W = binomial_h.search_Min();

	cout << W->info << endl;

	cout << "El binomial esta en la posicion: " << binomial_h.getHeap()->info << endl;
	
	return 0;
}