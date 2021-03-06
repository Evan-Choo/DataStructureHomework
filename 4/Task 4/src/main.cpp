//
// Created by Evan Choo on 11/27/17.
//

#include <iostream>
#include "BitreeNode.h"
#include <math.h>
#include <stack>
#include <queue>

using namespace std;

//inorder traversal function
void inorderTraversal(BitreeNode* root){

    stack<BitreeNode*> stack;

    BitreeNode* p = root;
    do{
        while(p){
            stack.push(p);
            p = p->leftChild;
        }
        if(!stack.empty()){
            p = stack.top();
            stack.pop();
            cout<<p->data<<" ";
            p = p->rightChild;
        }
    }while(p||!stack.empty());
}

//create binary tree function
BitreeNode* createCompleteBinaryTree(int* data, int size, BitreeNode* nodes[]){
    int cur = size;
    BitreeNode *l, *r, *newNode;

    while(cur!=0){
        if(cur*2<=size)
            l = nodes[cur*2];
        else
            l = NULL;

        if(cur*2+1<=size)
            r = nodes[cur*2+1];
        else
            r = NULL;

        newNode = new BitreeNode(l, data[cur-1], r);
        nodes[cur] = newNode;
        cur--;
    }

    return nodes[1];
}

//print the complete binary tree
void printBinaryTree(int sizeOfData, BitreeNode* nodes[]){
    int layers = floor(log((double)sizeOfData)/log((double)2))+1;
    int maxWidth = (int)pow(2, layers)-1;
    int endSpacing = maxWidth;
    int spacing;
    int numOfThisLayer;
    for(int i=1; i<=layers; i++){
        endSpacing = endSpacing/2;
        spacing = endSpacing*2+1;
        numOfThisLayer = (int)pow(2, i-1);

        int j;
        for(int j=0; j<endSpacing; j++)
            cout<<" ";

        int beginIndex = (int)pow(2, i-1);
        for(j=1; j<=numOfThisLayer; j++){
            cout<<nodes[beginIndex++]->data;
            for(int k=0; k<spacing; k++)
                cout<<" ";
            if(beginIndex==sizeOfData+1)
                break;
        }
        cout<<endl;
    }
}

//此时的参数为值传递，不会对原来的queue有影响
void printLevel(queue<BitreeNode*> queue1, int i){
    cout<<"Level "<<i+1<<"(from right to left): ";
    stack<BitreeNode*> stack1;
    while(!queue1.empty()){
        BitreeNode* tmp = queue1.front();
        stack1.push(tmp);
        queue1.pop();
    }
    while(!stack1.empty()){
        cout<<stack1.top()->data<<" ";
        stack1.pop();
    }
    cout<<endl;
}

//level order traversal function
void levelOrderTraversal(BitreeNode* root){
    queue<BitreeNode*> queue1;
    queue<BitreeNode*> queue2;

    queue1.push(root);
    int i = 0;

    do{
        //read nodes from queue1 and put the nodes of next level into queue2
        if(i%2==0){
            printLevel(queue1, i);

            while(!queue1.empty()){
                BitreeNode* p = queue1.front();
                queue1.pop();

                if(p->leftChild!=NULL)
                    queue2.push(p->leftChild);
                if(p->rightChild!=NULL)
                    queue2.push(p->rightChild);
            }

            i++;
            continue;
        }

        //read nodes from queue2 and put the nodes of next level into queue1
        if(i%2==1){
            printLevel(queue2, i);

            while(!queue2.empty()){
                BitreeNode* p = queue2.front();
                queue2.pop();

                if(p->leftChild!=NULL)
                    //cout<<p->leftChild->data<<"test"<<endl;
                    queue1.push(p->leftChild);
                if(p->rightChild!=NULL)
                    //cout<<p->rightChild->data<<"test"<<endl;
                    queue1.push(p->rightChild);
            }
            i++;
            continue;
        }

    }while(!queue1.empty()||!queue2.empty());
}


int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sizeOfdata = sizeof(data)/ sizeof(int);

    BitreeNode* nodes[sizeOfdata+1];
    for(int i = 0; i < sizeOfdata+1; i++){
        nodes[i] = NULL;
    }

    BitreeNode* root = createCompleteBinaryTree(data, sizeOfdata, nodes);

    cout<<"The original array is: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}"<<endl;
    cout<<endl;

    cout<<"The inorder traversal of the complete binary tree is: "<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<endl;

    cout<<"The graph of the complete binary tree is: "<<endl;
    printBinaryTree(sizeOfdata, nodes);
    cout<<endl;

    levelOrderTraversal(root);

    return 0;
}

