//
// Created by Evan Choo on 17/11/4.
//

#ifndef FIRST_STACK_H
#define FIRST_STACK_H

#include <assert.h>
#include <iostream>

class Stack{
public:
    explicit Stack(int=10);
    ~Stack(){delete[] elements;}
    void push(const int &item);
    int pop();
    int getTop();
    void makeEmpty() {top = -1;}
    int isEmpty() const {return top==-1;}
    int isFull() const {return top==maxSize-1;}
    void printOut();

private:
    int top;
    int *elements;
    int maxSize;
};

#endif //FIRST_STACK_H
