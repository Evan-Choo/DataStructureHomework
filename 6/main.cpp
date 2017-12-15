#include <iostream>
#include "MinimumHeap.h"

using namespace std;

void HuffmanCode(){
    char** hcodes;

}

int main() {
    double weights[5] = {0.0, 0.1, 0.3, 0.25, 0.05};
    char datas[5] = {'#', 'a', 'b', 'c', 'd'};

    MinimumHeap *minHeap = new MinimumHeap(
            weights,
            sizeof(weights)/ sizeof(double)-1,
            datas
    );

    return 0;

}