#include <iostream>
#include <vector>
#include <string>
#include "BinaryHeap.hpp"


BinaryHeap::BinaryHeap(){
  arr = new std::vector<int>();
  arr->push_back(0);
}

BinaryHeap::~BinaryHeap(){
  delete arr;
}

bool BinaryHeap::empty(){
  if(arr->size()>1)return false;
  return true;
}

int BinaryHeap::size(){
  return arr->size() - 1;
}

int BinaryHeap::top(){
  if(!this->empty()) return arr->at(1);
  else {
    std::cout << "Empty PQ exeption" << '\n';
    return -1;
  }

}
void BinaryHeap::swap(int* son, int* father){
	int cage1 = *father;
	*father = *son;
	*son = cage1;
}
void BinaryHeap::upheap(int* hijo, int* padre, int* i){
	swap(hijo,padre);
	*i = parent(*i);
}

void BinaryHeap::push(int n){
  int counter = 0;
  int i = this->size();
	arr->push_back(n);
	i++;
	while (i != 1 && arr->at(parent(i)) > arr->at(i)){
    upheap(&arr->at(i), &arr->at(parent(i)), &i);
	}
}
void BinaryHeap::pop(){
  if(this->empty()){
    std::cout << "Empty BinaryHeap exception" << '\n';
  } else {
    if (arr->size() == 2) {
        arr->clear();
      } else {
      //swap
			arr->at(1) = arr->at(arr->size()-1);
			arr->erase(arr->begin()+arr->size()-1);
			downheap(1);
	}
  }
}
void BinaryHeap::downheap(int root){
	int posL = 2 * root;
	int posR = posL + 1;

  int posVar = root;
  // printf("\t[root]: %d \t [posL]: %d \t[posR]: %d \n",root,posL,posR);
  if (posL <= arr->size()-1){
    int *Leftchild = &arr->at(posL);
    if(*Leftchild < arr->at(posVar))posVar = posL;
  }
  if (posR <= arr->size()-1) {
    int *Rightchild = &arr->at(posR);
    if(*Rightchild < arr->at(posVar))posVar = posR;
  }
  if (posVar != root){
    swap(&arr->at(root), &arr->at(posVar));
    downheap(posVar);
  }
}

void BinaryHeap::printBinaryHeap(std::string string1,int pos){
  // " - " significa que no tiene child
  if(pos >= arr->size()){
    std::cout<<string1 << " - " << '\n';
  } else {
    std::cout << string1;
    std::cout << arr->at(pos) << '\n';
    printBinaryHeap(string1 + tab,pos * 2);
    printBinaryHeap(string1 + tab,pos * 2 + 1);
  }
}
void BinaryHeap::printBinaryHeap(){
  int degree = 0;
  int numNodes = pow(2,degree);
  std::cout << "PRINTING: " << '\n';
  for(int i = 0; i < arr->size();++i){
    std::cout << arr->at(i) << ' ';
  }
  std::cout  << '\n';
  printBinaryHeap("",1);
}

std::vector<int> BinaryHeap::getVector(){
  std::vector<int> vec = *arr;
  return vec;
}
void BinaryHeap::printArr(){
  for(int i = 0; i < arr->size(); ++i){
    std::cout << arr->at(i) << " ";
  }
  printf("\n");
}
void BinaryHeap::unionBH(const std::vector<int>&vec){
  // std::cout << "UNION BH: FUNCTION" << '\n';
  for(int i = 1; i < vec.size(); ++i){
      arr->push_back(vec[i]);
  }
  
  int height = log2(this->size());
  int level = height + 1;
  // printf("\nTotal size: %d\n",arr->size());
  // printf("\nOriginal Heigh: %d \t Original level: %d\n",height,level);
  while(height >= 0){
    int posNodes = pow(2,height);
    int limit = std::min((int)pow(2,height+1),this->size() + 1);
    while(posNodes != limit){
    // printf("[posnNodes]: %d \n",posNodes);
    // printf("DownHeap function:\n ");
      downheap(posNodes);

      posNodes++;

    }

    height--;
  }
 
  // return *this;
}

bool BinaryHeap::isValid(){
  bool isvalid = true;
  for(int i = 1; i < arr->size(); ++i){
    // si sus hijos son menores
    if(i*2 < arr->size()){

      if(arr->at(i*2) < arr->at(i)){
        isvalid = false;
        break;
      }
    }
    if((i*2) + 1 < arr->size()){
        if(arr->at(i*2 + 1) < arr->at(i)){
          isvalid = false;
          break;
        }
    }
  }
  return isvalid;
}
