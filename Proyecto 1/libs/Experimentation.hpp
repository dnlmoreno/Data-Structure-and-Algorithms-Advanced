#pragma once

#include "Experimentation.hpp"
#include "BinaryHeap.hpp"
#include "BinomialHeap.hpp"
class Experimentation{

private:
    void fill(int);

public:
    Experimentation(/* args */);
    ~Experimentation();
    void debugBinaryHeap();
    void debugBinomialHeap();
};
