#pragma once

#include "Experimentation.hpp"
#include "BinaryHeap.hpp"
#include "BinomialHeap.hpp"
#include <time.h>
class Experimentation{

private:
    void fill(vi&,int);
    int getRand(int,int);
public:
    Experimentation(/* args */);
    ~Experimentation();
    void getInsertionTime();
    void getMergeTime();
    void debugBinaryHeap();
    void debugBinomialHeap();
};
