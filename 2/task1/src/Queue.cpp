//
// Created by Evan Choo on 17/11/4.
//


#include "Queue.h"

Queue::Queue(int sz):rear(0),front(0),maxSize(sz){
    elements = new int[maxSize];
    for(int i=0; i<maxSize; i++)
        elements[i]=0;
    assert(elements!=0);
}

void Queue::EnQueue(const int& item) {
    assert(!IsFull());
    rear=(rear+1)%maxSize;
    elements[rear] = item;
}

int Queue::DeQueue() {
    assert(!IsEmpty());
    front=(front+1)%maxSize;
    return elements[front];
}

int Queue::GetFront() {
    assert(!IsEmpty());
    return elements[front];
}

int Queue::GetRear(){
    assert(!IsEmpty());
    return elements[rear];
}

void Queue::DeQueueFromRear(){
    assert(!IsEmpty());
    rear=(rear-1+maxSize)%maxSize;
}

void Queue::printOut() {
    for(int i=0; i<this->Length(); i++){
        std::cout<<elements[(front+1+i)%maxSize]<<" ";
    }
}
