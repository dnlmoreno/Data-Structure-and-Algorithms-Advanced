#include <iostream>
#include "libs/Experimentation.hpp"
using namespace std;

int main(int argc, char* argv[]){
	Experimentation* exp = new Experimentation();
	// exp->getMergeTime();
	exp->debugBinomialHeap();
	return 0;
}
