#include "BinomialHeap.hpp"

/*********************************/
/*******    Node Class     *******/
/*********************************/

Nodo::Nodo(int info){
	child = NULL;
	sibling = NULL;
	padre = NULL;
	this->info = info;
	this->degree = 0;
}

Nodo::~Nodo(){
	delete child;
	delete sibling;
	delete padre;
}

/******************************************/
/*******    Binomial heap Class     *******/
/******************************************/

BinomialHeap::BinomialHeap(){
	head = NULL;
	this->mysize = 0;
}

BinomialHeap::~BinomialHeap(){
	delete head;
}

Nodo* BinomialHeap::getHeap(){
	return head;
}

bool BinomialHeap::insert(int info){
	// cout<<"insert function"<<endl;
	// Heap esta vacio
	if(head == NULL){
		// cout << "entre head null";
		head = new Nodo(info);
		this->mysize++;
		return true;
	}

	// Heap no esta vacio
	
	Nodo* new_heap = NULL;
	new_heap = new Nodo(info);
	head = union_BH(head, new_heap);
	//delete new_heap;
	this->mysize++;
	return true;
}


Nodo* BinomialHeap::search_Min(){
	Nodo* x = head;
	Nodo* min_node = NULL;

	// Se toma el primer valor como minimo y puntero al siguiente BT
	int min_value = x->info;
	x = x->sibling;

	// Se recorre la raiz de todos los BT's del heap
	while(x != NULL){
		// Se guarda el valor y nodo minimo
		if(x->info < min_value){
			min_value = x->info;
			min_node = x;
		}
		// Puntero se mueve hacia adelante
		x = x->sibling;
	}
	return min_node;
}

int BinomialHeap::size(){
	return this->mysize;
}
Nodo* BinomialHeap::union_BH(Nodo* head_BT1, Nodo* head_BT2){
	// Comprueba si los heaps ingresados tienen elementos
	if(head_BT1 == NULL && head_BT2 == NULL) return NULL;

	// std::cout<<"me caigo en union"<<endl;;

	// Se conectan ambos heap en uno solo 
	head = __merge(head_BT1, head_BT2);
	
	// Punteros que permiten recorrer el heap
	Nodo* prev = NULL;
	Nodo* x = head;
	Nodo* next = head->sibling;

	// Se recorren todos los nodos de la raiz
	while(next != NULL){

		// Caso 1 y Caso 2.
		// Se mueven los punteros hacia adelante
		if((x->degree != next->degree) || ((next->sibling != NULL) && (next->sibling)->degree == x->degree)){
			prev = x; 
			x = next;
		}
		else{
			// Caso 3.
			// Se remueve el BT next de la raiz, se adjunta a x, se vincula el nuevo sibling, padre e hijo y se aumenta el grado
			if(x->info <= next->info){
				x->sibling = next->sibling;
				__link_BT(next, x);
			}
			// Caso 4.
			// Se remueve el BT x de la raiz, se adjunta a next, se vincula el nuevo sibling, padre e hijo y se aumenta el grado
			else{
				if(prev == NULL) head = next;
				else prev->sibling = next;
				__link_BT(x, next);
				x = next;
			}
		}
		// Se avanza en la raiz de los BT's contenidos en el heap
		next = x->sibling;
	}
	// std::cout << "Ya está unido"<<endl;
	// std::cout << "printing"<<endl;
	// this->PrintBinomialHeap();
	// std::cout<< "saliendo de union"<<endl;
	return head;
}
void BinomialHeap::union_BH(BinomialHeap* bh1,BinomialHeap* bh2){
	Nodo* p = this->union_BH(bh1->getHeap(),bh2->getHeap());
}

Nodo* BinomialHeap::__merge(Nodo* head_BT1, Nodo* head_BT2){
	// std::cout<<"me caigo en merge"<<endl;
	// Si un heap ingresado esta vacio devuelve el heap no vacio
	if(head_BT1 == NULL) return head_BT2;
	if(head_BT2 == NULL) return head_BT1;

	Nodo* aux = NULL;

	// Puntero que señala el heap que comienza con el BT de menor grado
	if (head_BT1->degree <= head_BT2->degree) head = head_BT1;
	else head = head_BT2;
	
	while(head_BT1 != NULL && head_BT2 != NULL){
		
		// Avanza el puntero al BT siguiente del heap1
		if(head_BT1->degree < head_BT2->degree){
			head_BT1 = head_BT1->sibling;
		}
		// Se avanza el puntero al BT siguiente del heap2 y se vincula el BT actual del heap general con el heap1
		else if(head_BT1->degree > head_BT2->degree){
			aux = head_BT2->sibling;
			head_BT2->sibling = head_BT1;
			head_BT2 = aux;
		}
		// Se avanza el puntero al BT siguiente del heap1 y se vincula el BT actual del heap general con el heap2
		else{
			aux = head_BT1->sibling;
			head_BT1->sibling = head_BT2;
			head_BT1 = aux;
		}
	}
	// Retorna el heap general (ambos heaps vinculados)
	return head;
}

void BinomialHeap::__link_BT(Nodo* head_BT1, Nodo* head_BT2){
	// Vinculación del nuevo sibling, padre e hijo y se aumenta el grado
	head_BT1->padre = head_BT2;
    head_BT1->sibling = head_BT2->child;
    head_BT2->child = head_BT1;
    head_BT2->degree = head_BT2->degree + 1;
}

void BinomialHeap::Display2(Nodo* H){
	if(H == NULL){
		cout<<"The heap is empty"<<endl;
	}
	Nodo* p;
	p = H;
	int IDTree = 1;
	std::string tab = "\t";
	while(p  != NULL){
		cout<<"ID Tree: "<<IDTree<<endl;
		std::cout<<p->info<<endl;
		DisplayBhTree(p->child,tab);
		p = p->sibling;
		IDTree++;
		std::cout <<'\n' << "*************************************" <<'\n';
	}

}

void BinomialHeap::DisplayBhTree(Nodo* H,std::string tab){
	if(H == NULL){
		std::cout << tab << " - " << '\n';
	} else {
		std::cout << tab;
		std::cout << H->info <<'\n';
		DisplayBhTree(H->child, tab + '\t');
		DisplayBhTree(H->sibling, tab);
	} 

}
void BinomialHeap::PrintBinomialHeap(){
	Display2(this->head);
}
/*
Condiciones de validez:
	1. nodos visitados = arbol->size
	2. cada arbol tiene que ser un heap
*/
bool BinomialHeap::validNode(Nodo *p){
	if(p->padre->info > p->info)return false;	
	return true;
}
void BinomialHeap::validTree(Nodo* p,bool& valid,int& numVisited){
	if(p != nullptr && valid){
		numVisited++;
		// check if every node is valid
		valid = validNode(p);
		if(!valid)return;
		validTree(p->child,valid,numVisited);
		validTree(p->sibling,valid,numVisited);
	}
}
bool BinomialHeap::isValid(){
	if(this->head== nullptr && this->mysize == 0){
		cout<<"The heap is empty"<<endl;
		return true;
	}
	Nodo* p;
	p = this->head;
	int currentsize = 0;
	std::string tab = "\t";
	bool check = true;
	// loop towards the binomial heap
	while(p  != nullptr){
		currentsize++;
		// check if each bi-tree is valid
		validTree(p->child,check,currentsize);
		if(!check){
			cout << "not valid tree exeption"<<endl;
			return false;
		}
		p = p->sibling;
	}
	if(currentsize != this->size()){
		std::cout << "not same size exeption"<<endl;
		std::cout << "currentSize: "<<currentsize;
		std::cout << " this->size "<<this->size() << "\n";
		return false;
	}
	return true;
}