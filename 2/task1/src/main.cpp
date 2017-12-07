//
// Created by Evan Choo on 17/11/4.
//

#include <iostream>

#include "Stack.h"
#include "Queue.h"

using namespace std;

void recursion(int ints[], int cur, int n, Stack& stack, Queue& outQueue){

    if(cur >= n){
        outQueue.printOut();
        stack.printOut();
        cout<<endl;
        return;
    }

    stack.push(ints[cur]);
    recursion(ints, cur+1, n, stack, outQueue);

    stack.pop();
    if(!stack.isEmpty()){
        outQueue.EnQueue(stack.getTop());
        stack.pop();
        recursion(ints, cur, n, stack, outQueue);
        stack.push(outQueue.GetRear());
        outQueue.DeQueueFromRear();
    }

}

int main(){

    int ints[] = {1, 2, 3, 4};

    Stack stack(sizeof(ints)/ sizeof(int));
    Queue outQueue(sizeof(ints)/ sizeof(int));

    recursion(ints, 0, sizeof(ints)/ sizeof(int), stack, outQueue);

}

