//
// Created by Evan Choo on 11/27/17.
//

#include <iostream>
#include "BitreeNode.h"
#include <stack>
#include <queue>

using namespace std;

//inorder traversal function
void inorderTraversal(BitreeNode* root){

    stack<BitreeNode*> stack;

    cout<<endl;
    cout<<"Inorder traversal of the tree: ";

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
    cout<<endl;
}

//此时的参数为值传递，不会对原来的queue有影响
void printLevel(queue<BitreeNode*> queue1, int i){
    cout<<"Level "<<i+1<<": ";
    while(!queue1.empty()){
        BitreeNode* tmp = queue1.front();
        cout<<" "<<tmp->data;
        queue1.pop();
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

int findParent(char p, int length, BitreeNode* nodes[]){
    for(int i=0; i<length; i++){
        if(nodes[i]->data==p)
            return i;
    }
    return -1;
}

BitreeNode* makeTree(string s){
    int length = s.length();
    int stringIndex = 0;
    int nodesIndex = 0;
    BitreeNode* nodes[length];

    BitreeNode* root = new BitreeNode(NULL, s[stringIndex++], NULL);
    nodes[nodesIndex++] = root;

    while(s[stringIndex]!='\0'){
        BitreeNode* p = new BitreeNode(NULL, s[stringIndex], NULL);
        nodes[nodesIndex] = p;

        if(s[stringIndex+3]!=')'){
            int i = findParent(s[stringIndex+2], length, nodes);
            if(s[stringIndex+3]=='L')
                nodes[i]->leftChild=nodes[nodesIndex];
            if(s[stringIndex+3]=='R')
                nodes[i]->rightChild=nodes[nodesIndex];

            stringIndex += 5;
            nodesIndex++;
            continue;
        }

        if(s[stringIndex+3]==')'){
            int i = findParent(s[stringIndex+2], length, nodes);
            if(nodes[i]->leftChild==NULL)
                nodes[i]->leftChild=p;
            else if(nodes[i]->rightChild==NULL)
                nodes[i]->rightChild=p;
            else
                runtime_error("Not a binary tree!");

            stringIndex += 4;
            nodesIndex++;
            continue;
        }
    }

    return root;
}

int main() {
    string s;
    cin>>s;

    BitreeNode* root = makeTree(s);

    inorderTraversal(root);

    levelOrderTraversal(root);

    return 0;
}

