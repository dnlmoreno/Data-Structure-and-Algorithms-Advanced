#ifndef BH_H
#define BH_H

#include <vector>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> vi;
typedef std::string str;
class BinaryHeap{

private:
	void swap(int*, int*);
	void downheap(int);
	std::vector<int> *arr;
	void printBinaryHeap(str,int);
	/*
	void printIntevalTree(Node*,std::string);

	*/
public:
	BinaryHeap();
	~BinaryHeap();
	bool empty();
	int size();
	int top();
	void push(int);
	void pop();
	void printBinaryHeap();

	std::vector<int> getVector();
	// cambie el parámetro de comparación para hacerlo MIN O MAX
	bool isValid();
	BinaryHeap unionBH(const std::vector<int>& arr);

};
#endif
