//
// Created by Evan Choo on 11/27/17.
//

#ifndef HOMEWORK4_BITREENODE_H
#define HOMEWORK4_BITREENODE_H

class BitreeNode {
public:
    BitreeNode* leftChild;
    int data;
    BitreeNode* rightChild;
    BitreeNode(BitreeNode* l, int data, BitreeNode* r);
    BitreeNode();
};

#endif //HOMEWORK4_BITREENODE_H
