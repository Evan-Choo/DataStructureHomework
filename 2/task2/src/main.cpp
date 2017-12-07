#include <iostream>

using namespace std;

void printArray(int A[], int sizeOfArray){
    for(int i=0; i<sizeOfArray; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void recursion(int A[], int curNum, int n, int curPosFor[]){

     while(curPosFor[curNum]+curNum+1 < 2*n && curNum>=1 && curNum<=n){
        if(A[curPosFor[curNum]]==0 && A[curPosFor[curNum]+curNum+1]==0){
            A[curPosFor[curNum]] = curNum;
            A[curPosFor[curNum]+curNum+1] = curNum;
            if(curNum<n){
                recursion(A, curNum+1, n, curPosFor);
            }else{
                break;
            }
        }else{
            curPosFor[curNum]++;
        }
    }

    int counter=0;
    for(int i=0; i<2*n; i++){
        if(A[i]!=0)
            counter++;
    }

    if(counter==2*n){
        printArray(A, 2*n);
        A[curPosFor[curNum]]=0;
        A[curPosFor[curNum]+curNum+1]=0;
        A[curPosFor[curNum-1]]=0;
        A[curPosFor[curNum-1]+curNum]=0;
        curPosFor[curNum-1]++;
        curPosFor[curNum]=0;
    }else{
        A[curPosFor[curNum-1]]=0;
        A[curPosFor[curNum-1]+curNum]=0;
        curPosFor[curNum-1]++;
        curPosFor[curNum]=0;
    }
}

int main() {

    cout<<"enter a positive integer:"<<endl;
    int n;
    cin>>n;

    int A[2*n];
    for(int i=0; i<2*n; i++){
        A[i]=0;
    }

    int curPosFor[n+1];
    for(int i=0; i<n+1; i++){
        curPosFor[i]=0;
    }

    recursion(A, 1, n, curPosFor);

}