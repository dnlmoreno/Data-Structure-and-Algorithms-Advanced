#include "Experimentation.hpp"

Experimentation::Experimentation(/* args */){
}

Experimentation::~Experimentation(){
}
// mejorar, se cae con dos números consecutivos :c 
int Experimentation::getRand(int FROM,int TO){
  int randPos = (rand()%(FROM - TO + 1)+FROM);
  return randPos;
}
void Experimentation::fillUnordered(vi& vec,int from, int n){
    for(int i = 0; i < n; ++i){
		vec.push_back(getRand(from,n));
	}
}
void Experimentation::fillAscending(vi& vec,int from, int n){
	for(int i = from; i < n; ++i){
		vec.push_back(i);
	}
}

void Experimentation::fillDescending(vi& vec,int from, int n){
	for(int i = n; i >= from;--i){
		vec.push_back(i);
	}
}
void Experimentation::fillEqual(vi& vec, int n,int num){
	for(int i = 0; i < n;++i){
		vec.push_back(num);
	}
}
void Experimentation::debugBinaryHeap(){
	vi vec;
	int millon = 1000000;
	fillUnordered(vec,0,100*millon);
	BinaryHeap *binaryheap1 = new BinaryHeap();
	for(int i = 0; i < vec.size();++i){
		binaryheap1->push(vec[i]);
	}
	// binaryheap1->printBinaryHeap();
	BinaryHeap *binaryheap2 = new BinaryHeap();
	fillUnordered(vec,0,1*millon);
	for(int i = 0; i < vec.size(); ++i){
		binaryheap2->push(vec[i]);
	}
	// printf("original size bh2: %d\n",binaryheap2->size());

	vec = binaryheap1->getVector();
	binaryheap2->unionBH(vec);	
	// printf("after size bh2: %d\n",binaryheap2->size());

	// binaryheap1->printBinaryHeap();
	// binaryheap2->printBinaryHeap();
	if(binaryheap2->isValid())std::cout<<"valid binaryheap2\n";
	if(binaryheap1->isValid())std::cout<<"valid binaryheap1\n";
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
		// tamaño de elementos
		for(int n = 10000; n <= 100000; n+=10000){

			BinaryHeap* binaryheap1 = new BinaryHeap();
			BinaryHeap* binaryheap2 = new BinaryHeap();
			BinaryHeap* binaryheap3 = new BinaryHeap();

			vi vec1,vec2,vec3;

			double counter1 = 0;
			double counter2 = 0;
			double counter3 = 0;
			// cantidad de repeticiones para promediar
    		for(int j = 0; j < rep; ++j){

				fillAscending(vec1,0,n);
				fillDescending(vec2,0,n);
				fillUnordered(vec3,0,n);
				
				// inserción ascendente
    			clock_t start = clock();
				for(int k = 0; k < vec1.size(); ++k){
					binaryheap1->push(vec1[k]);
				}
				clock_t end = clock();
				counter1 += (double)(end - start);
	
				// inserción descendente
				start = clock();
				for(int k = 0; k < vec2.size(); ++k){
					binaryheap2->push(vec2[k]);
				}
				end = clock();
				counter2 += (double)(end - start);
				
				// inserción desordenada
				start = clock();
				for(int k = 0; k < vec3.size(); ++k){
					binaryheap3->push(vec3[k]);
				}
				end = clock();
				counter3 += (double)(end - start);

				vec1.clear();
				vec2.clear();
				vec3.clear();
			}
			// promedio de insertar n elementos
			double duracionAsc = ((counter1/ CLOCKS_PER_SEC)/rep)*1000;
		    double duracionDes = ((counter2/ CLOCKS_PER_SEC)/rep)*1000;
		    double duracionUno = ((counter3/ CLOCKS_PER_SEC)/rep)*1000;
		    
			// clock lo mide en segundos por lo que hay que convertirlo a milisegundos
    		// double duracion = (((double)(clock() - start) / CLOCKS_PER_SEC)/rep) * 1000;

    		std::cout <<duracionAsc<<";"<<duracionDes<<";"<<duracionUno<< '\n';

			delete binaryheap1;
			delete binaryheap2;
			delete binaryheap3;
  		}
	
	
}

void Experimentation::getMergeTime(){
	int rep = 10000;
		// tamaño de elementos
		for(int n = 10000; n <= 100000; n+=10000){

			BinaryHeap* binaryheap1 = new BinaryHeap();
			BinaryHeap* binaryheap2 = new BinaryHeap();
			
			BinaryHeap* binaryheap3 = new BinaryHeap();
			BinaryHeap* binaryheap4 = new BinaryHeap();
			
			BinaryHeap* binaryheap5 = new BinaryHeap();
			BinaryHeap* binaryheap6 = new BinaryHeap();
			
			vi vec1,vec2,vec3,vec4,vec5,vec6;

			double counter1 = 0;
			double counter2 = 0;
			double counter3 = 0;
			// cantidad de repeticiones para promediar
    		for(int j = 0; j < rep; ++j){

				//uno con elementos mayores que otro
				if(j == 0)fillAscending(vec1,0,n);
				if(j == 0)fillDescending(vec2,n,n*2);

				for(int k = 0; k < vec1.size(); ++k){
					binaryheap1->push(vec1[k]);
				}
				for(int k = 0; k < vec2.size(); ++k){
					binaryheap2->push(vec2[k]);
				}
				clock_t start = clock();
				binaryheap1->unionBH(binaryheap2->getVector());
				clock_t end = clock();
				counter1 += (double)(end - start);

				// dos con elementos similares
				fillUnordered(vec3,0,n);
				fillUnordered(vec4,0,n);
				for(int k = 0; k < vec3.size(); ++k){
					binaryheap3->push(vec3[k]);
				}
				for(int k = 0; k < vec4.size(); ++k){
					binaryheap4->push(vec4[k]);
				}

    			 start = clock();
				binaryheap3->unionBH(binaryheap4->getVector());
				 end = clock();
				counter2 += (double)(end - start);

				// uno con elementos disintos y otro con iguales
				fillUnordered(vec5,0,n);
				if(j == 0)fillEqual(vec6,n,10000);
				for(int k = 0; k < vec5.size(); ++k){
					binaryheap5->push(vec5[k]);
				}
				for(int k = 0; k < vec6.size(); ++k){
					binaryheap6->push(vec6[k]);
				}

    			 start = clock();
				binaryheap5->unionBH(binaryheap6->getVector());
				 end = clock();
				counter3 += (double)(end - start);
	
				// vec1.clear();
				// vec2.clear();
				vec3.clear();
				vec4.clear();
				vec5.clear();
				// vec6.clear();
			}
			// promedio de insertar n elementos
			double duracionAsc = ((counter1/ CLOCKS_PER_SEC)/rep)*1000;
		    double duracionDes = ((counter2/ CLOCKS_PER_SEC)/rep)*1000;
		    double duracionUno = ((counter3/ CLOCKS_PER_SEC)/rep)*1000;
		    
			// clock lo mide en segundos por lo que hay que convertirlo a milisegundos
    		// double duracion = (((double)(clock() - start) / CLOCKS_PER_SEC)/rep) * 1000;

    		std::cout <<duracionAsc<<";"<<duracionDes<<";"<<duracionUno<< '\n';

			delete binaryheap1;
			delete binaryheap2;
			delete binaryheap3;
  		}
	
}