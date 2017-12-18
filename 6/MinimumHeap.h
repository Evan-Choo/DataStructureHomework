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
    char** hcodes;
    int firstDimension=0;
    int secondDimension=0;

public:
    MinimumHeap(double weights[], int weightSize, char datas[]);
    void adjustDown(int last);
    void createHuffmanTree();
    int findLastIndex();
    void HuffmanCode(Node n);
    void printHuffmanCode(int i, int j, char** hcodes);
};

#endif //TASK6_MINIMUMHEAP_H
