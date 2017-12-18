#include <iostream>
#include "MinimumHeap.h"

using namespace std;

void HuffmanCode(){
    char** hcodes;

}

int main() {
    double weights[7] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    char datas[7] = {'#', 'a', 'b', 'c', 'd', 'e', 'f'};

    MinimumHeap *minHeap = new MinimumHeap(
            weights,
            sizeof(weights)/ sizeof(double)-1,
            datas
    );

    minHeap->createHuffmanTree();

    return 0;

}