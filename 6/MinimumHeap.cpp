//
// Created by Evan Choo on 12/15/17.
//

#include "MinimumHeap.h"

MinimumHeap::MinimumHeap(double weights[], int weightSize, char datas[]){
    nodes=new Node[weightSize+1];
    this->size=weightSize;
    for(int i=1; i<=weightSize; i++){
        nodes[i].weight=weights[i];
        nodes[i].data=datas[i];
    }
    for(int i=weightSize; i>1; i--){
        if(nodes[i].weight<nodes[i/2].weight){
            Node tmp=nodes[i];
            nodes[i]=nodes[i/2];
            nodes[i/2]=tmp;
        }
    }
}

void MinimumHeap::adjustDown(int last) {
    for(int i=1; i<=last; i++){
        int j=(nodes[i*2].weight<nodes[i*2+1].weight) ? i*2 : i*2+1;

        //出栈条件，当前节点权重同时小于或等于左右孩子节点权重
        if(nodes[i].weight<=nodes[i*2].weight&&nodes[i].weight<=nodes[i*2+1])
        if(nodes[i].weight<nodes[j].weight){
            Node tmp=nodes[i];
            nodes[i]=nodes[j];
            nodes[j]=tmp;
        }
    }
}

void MinimumHeap::createHuffmanTree() {
    Node tmp1=nodes[1];
    int i=findLastIndex();
    nodes[i].data='#';
    nodes[i].weight=0.0;
    adjustDown(i);

}

//用于找出nodes中最后一个非空节点的index
int MinimumHeap::findLastIndex() {
    for(int i=size; i>=1; i--){
        if(nodes[i].weight!=0)
            return i;
    }
    return -1;
}

