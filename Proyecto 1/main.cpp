#include <iostream>
#include "libs/BinomialHeap.hpp"
#include "libs/BinaryHeap.hpp"
#include "libs/Experimentation.hpp"
using namespace std;

int main(int argc, char* argv[]){
	cout << "Hola Mundo!" << endl;
	BinomialHeap binomial_h;
	BinomialHeap binomial_h2;
	Nodo* H = NULL;
	Nodo* H1 = NULL;
	Nodo* H2 = NULL;
	Nodo* W = NULL;

	//cout << "El binomial esta en la posicion: " << binomial_h.getHeap() << endl;
	//cout << "El binomial esta en la posicion: " << &binomial_h << endl;

	BinaryHeap* bh = new BinaryHeap();

	binomial_h.insert(5);
	binomial_h.insert(8);
	bh->push(1);
	bh->push(3);
	bh->push(5);
	bh->push(6);
	bh->push(1);
	bh->printBinaryHeap();
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

	return 0;
}
