//
// Created by Evan Choo on 17/11/4.
//

#ifndef FIRST_QUEUE_H
#define FIRST_QUEUE_H

#include <assert.h>
#include <iostream>

class Queue{
public:
    explicit Queue(int=10);
    ~Queue(){delete[] elements;}
    void EnQueue(const int& item);
    int DeQueue();
    int GetFront();
    int GetRear();
    void DeQueueFromRear();
    void MakeEmpty(){front=rear=0;}
    int IsEmpty() const {return front==rear;}
    int IsFull() const {return (rear+1)%maxSize==front;}
    int Length() const {return (rear-front+maxSize)%maxSize;}
    void printOut();

private:
    int rear,front;
    int *elements;
    int maxSize;
};

#endif //FIRST_QUEUE_H
