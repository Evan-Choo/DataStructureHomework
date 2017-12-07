//
// Created by Evan Choo on 17/11/4.
//

#include "Stack.h"

Stack::Stack(int s):top(-1), maxSize(s) {
    elements = new int[maxSize];
    assert(elements != 0);
}

void Stack::push(const int &item) {
    assert(!isFull());
    elements[++top]=item;
}

int Stack::pop() {
    assert(!isEmpty());
    return elements[top--];
}

int Stack::getTop() {
    assert(!isEmpty());
    return elements[top];
}

void Stack::printOut() {
    for(int i=top; i>-1; i--)
        std::cout << elements[i]<<" ";
}

