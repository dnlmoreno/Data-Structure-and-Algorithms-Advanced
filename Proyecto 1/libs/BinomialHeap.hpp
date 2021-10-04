#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include <iostream>
#include <string>
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
private:
	Nodo* head;
	int mysize;
	Nodo* __merge(Nodo* head_BT1, Nodo* head_BT2);
	void __link_BT(Nodo* head_BT1, Nodo* head_BT2);
	void Display2(Nodo* H);
	void DisplayBhTree(Nodo* H,std::string);
	void validTree(Nodo*,bool&,int&);
	bool validNode(Nodo*);
public:
	BinomialHeap();
	~BinomialHeap();

	Nodo* getHeap();
	int size();
	bool insert(int info);
	Nodo* search_Min();
	Nodo* union_BH(Nodo* head_BT1, Nodo* head_BT2);
	void union_BH(BinomialHeap*,BinomialHeap*);
	void PrintBinomialHeap();
	void displayABIT(Nodo *h);
	bool isValid();

};

#endif