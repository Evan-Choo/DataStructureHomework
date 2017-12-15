//
// Created by Evan Choo on 12/15/17.
//

#ifndef TASK6_MINIMUMHEAP_H
#define TASK6_MINIMUMHEAP_H

#include "Node.h"
#include <iostream>

using namespace std;

class MinimumHeap{
private:
    Node* nodes;
    int size;

public:
    MinimumHeap(double weights[], int weightSize, char datas[]);
    void adjustDown(int last);
    void createHuffmanTree();
    int findLastIndex();
};

#endif //TASK6_MINIMUMHEAP_H
