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

void BinaryHeap::push(int n){
  int pos = arr->size();
  int fatherPos = pos/2;

  arr->push_back(n);

  while(pos!=1 && arr->at(fatherPos) > arr->at(pos)){
    swap(&arr->at(pos),&arr->at(fatherPos));
    pos = fatherPos;
    fatherPos = pos/2;
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
	int posR = posR + 1;

  int posVar = root;

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

void BinaryHeap::printBinaryHeap(std::string tab,int pos){
  // " - " significa que no tiene child
  if(pos >= arr->size()){
    std::cout<<tab << " - " << '\n';
  } else {
    std::cout << tab;
    std::cout << arr->at(pos) << '\n';
    printBinaryHeap(tab + '\t',pos * 2);
    printBinaryHeap(tab + '\t',pos * 2 + 1);
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
/*
void IntervalTree::printIntevalTree(){
  std::cout << "NODE"<<'\t'<<"key"<<'\t'<<"height"<<'\t'<<"node"<<'\t'<<"Dir Father" << '\n';
  printIntevalTree(root,"");
}
*/
/*
void IntervalTree::printIntevalTree(Node* node,std::string Tab){
    if(node == NULL){
      std::cout<<Tab<< " - " << '\n';
    }
    else {
      std::cout << Tab;
      printNode(node);
      printIntevalTree(node->left,Tab + '\t');
      printIntevalTree(node->right,Tab + '\t');

    }
  }
  void IntervalTree::printNode(Node *node){
    if(node != NULL){
      std::cout<<"Y: "<<'('<< node->intervalY.first <<","<<node->intervalY.second<<" X,("<<node->intervalX.first<<','<<node->intervalX.second<<"): "<< '\t';
      std::cout << node->key <<'\t'<<node->height<<'\t';
      std::cout << node << '\t';
      if(node->father!=NULL)std::cout << node->father << '\n';
      else std::cout << "NULL" << '\n';
    } else std::cout << "NULL" << '\n';
  }
*/
std::vector<int> BinaryHeap::getVector(){
  std::vector<int> vec = *arr;
  return vec;
}

BinaryHeap BinaryHeap::unionBH(const std::vector<int>&vec){
  std::cout << "UNION BH: FUNCTION" << '\n';
  std::cout << "this->size1:  "<<this->size() << '\n';
  for(int i = 1; i < vec.size(); ++i){
      arr->push_back(vec[i]);
  }
  for(int i = 0; i < arr->size(); ++i){
    std::cout << arr->at(i) << ' ';
  }
  std::cout << "this->size1:  "<<this->size() << '\n';

  int height = log2(this->size());
  int level = height + 1;
  while(height >= 0){
    std::cout << "me caigo 1" << '\n';
    int posNodes = pow(2,height);
    int limit = std::min((int)pow(2,height+1),this->size() + 1);

    while(posNodes != limit){
      std::cout << "me caigo 2" << '\n';

      downheap(posNodes);
      std::cout << "me caigo 3" << '\n';

      posNodes++;

    }
    std::cout << "me caigo 3" << '\n';

    height--;
  }
  return *this;
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
    if(i*2 + 1 < arr->size()){
      if(i*2 + 1 < arr->size()){
        if(arr->at(i*2 + 1) < arr->size()){
          isvalid = false;
          break;
        }
      }
    }
  }
  return isvalid;
}
