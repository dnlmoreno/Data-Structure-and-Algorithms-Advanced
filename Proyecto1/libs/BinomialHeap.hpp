#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include <iostream>

using namespace std;

class Nodo{
public:
	int info;
	int degree;
	Nodo* child;
	Nodo* sibling;
	Nodo* padre;
	Nodo(int valor);
	~Nodo();
private:
};

class BinomialHeap{
public:
	BinomialHeap();
	~BinomialHeap();

	Nodo* getHeap();

	bool insert(int info);
	Nodo* search_Min();
	Nodo* union_BH(Nodo* head_BT1, Nodo* head_BT2);
	
	int Display(Nodo* H);

private:
	Nodo* head;
	Nodo* __merge(Nodo* head_BT1, Nodo* head_BT2);
	void __link_BT(Nodo* head_BT1, Nodo* head_BT2);
};

#endif