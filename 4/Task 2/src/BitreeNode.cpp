//
// Created by Evan Choo on 11/27/17.
//

#include "BitreeNode.h"
#include <iostream>

using namespace std;

BitreeNode::BitreeNode(BitreeNode* l, char data, BitreeNode* r) {
    this->leftChild=l;
    this->data=data;
    this->rightChild=r;
}

BitreeNode::BitreeNode():leftChild(NULL), data('\0'), rightChild(NULL) {}

