//
// Created by Evan Choo on 11/27/17.
//

#include <iostream>
#include "BitreeNode.h"
#include <stack>

using namespace std;

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

    cout<<endl;
}

int main() {

    BitreeNode* n1 = new BitreeNode(NULL, 1, NULL);
    BitreeNode* n3 = new BitreeNode(NULL, 3, NULL);
    BitreeNode* n5 = new BitreeNode(NULL, 5, NULL);
    BitreeNode* n4 = new BitreeNode(n3, 4, n5);
    BitreeNode* n2 = new BitreeNode(n1, 2, n4);
    BitreeNode* n7 = new BitreeNode(NULL, 7, NULL);
    BitreeNode* root = new BitreeNode(n2, 6, n7);

    cout<<"The inorder traversal of a tree: ";

    inorderTraversal(root);

    return 0;
}

