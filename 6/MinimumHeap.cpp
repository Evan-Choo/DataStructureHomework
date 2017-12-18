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
    hcodes= new char*[size];
    for(int k=0; k<size; k++){
        hcodes[k]=new char[15];
    }
}

void MinimumHeap::adjustDown(int last) {
    for(int i=1; i*2<=last; i++){
        //取左右孩子中权重较小的一个，如果i＊2+1在nodes范围之外，则较小的一个是i＊2；因为for循环条件中已经限制了i＊2<=last，不用考虑权重为0的情况
        int j=0;
        if(i*2+1>last){
           j=i*2;
        }else{
            j=(nodes[i*2].weight<nodes[i*2+1].weight) ? i*2 : i*2+1;
        }

        //出循环条件，当前节点权重小于或等于左右孩子中较小一个的权重
        if(nodes[i].weight<=nodes[j].weight){
            break;
        }

        if(nodes[i].weight>nodes[j].weight){
            Node tmp=nodes[i];
            nodes[i]=nodes[j];
            nodes[j]=tmp;
            i=j-1;
        }
    }
}

void MinimumHeap::createHuffmanTree() {
    int i=findLastIndex();
    while(i>1){
        i=findLastIndex();
        Node tmp1=nodes[1];

        nodes[1]=nodes[i];
        nodes[i].data='#';
        nodes[i].weight=0.0;

        i-=1;
        adjustDown(i);
        Node tmp2=nodes[1];

        Node* tmp3=new Node(tmp1.weight, tmp1.data, tmp1.left, tmp1.right);
        Node* tmp4=new Node(tmp2.weight, tmp2.data, tmp2.left, tmp2.right);
        Node* tmp5 = new Node(tmp1.weight+tmp2.weight, '#', tmp3, tmp4);
        nodes[1]=*tmp5;

        adjustDown(i);
    }
    HuffmanCode(nodes[1]);
}

//用于找出nodes中最后一个非空节点的index
int MinimumHeap::findLastIndex() {
    for(int i=size; i>=1; i--){
        if(nodes[i].weight!=0)
            return i;
    }
    return -1;
}

void MinimumHeap::HuffmanCode(Node n) {
    Node cur=n;

    if(cur.left!=NULL){
        if(cur.left->data=='#'){
            hcodes[firstDimension][secondDimension++]='0';
            HuffmanCode(*cur.left);
        }else{
            hcodes[firstDimension++][secondDimension]='0';
            cout<<cur.left->data<<": ";
            printHuffmanCode(firstDimension-1, secondDimension--, hcodes);
        }
    }
    if(cur.right!=NULL){
        if(cur.right->data=='#'){
            hcodes[firstDimension][secondDimension++]='1';
            HuffmanCode(*cur.right);
        }else{
            hcodes[firstDimension++][secondDimension]='1';
            cout<<cur.left->data<<": ";
            printHuffmanCode(firstDimension-1, secondDimension, hcodes);
        }
    }
}

void MinimumHeap::printHuffmanCode(int i, int j, char** hcodes){
    for(int k=0; k<=j; k++){
        cout<<hcodes[i][k];
    }
    cout<<endl;
}
