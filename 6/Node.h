//
// Created by Evan Choo on 12/15/17.
//

#ifndef TASK6_NODE_H
#define TASK6_NODE_H


#include <clocale>

class Node{
public:
    double weight;
    char data;
    Node* left;
    Node* right;

    Node(double weight, char data, Node *left, Node *right) : weight(weight), data(data), left(left), right(right) {}
    Node():weight(0.0), data('#'), left(NULL), right(NULL){}
};


#endif //TASK6_NODE_H
