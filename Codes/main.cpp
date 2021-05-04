#include <iostream>
#include "OptimalBST.h"

int main(){
    // three example sets of probabilities
    float P1[] = {0.0f,0.1f,0.2f,0.4f,0.3f};
    float P2[] = {0.0f,0.1f,0.2f,0.2f,0.5f};
    float P3[] = {0.0f,0.4f,0.1f,0.2f,0.3f};

    OptimalBST optimalBSTArray[] = {OptimalBST(P1,4),OptimalBST(P2,4),OptimalBST(P3,4)};

    for(int i = 0; i < 3; i++) {
        optimalBSTArray[i].generateOptimalBST();

        optimalBSTArray[i].printCostTable();
        std::cout << std::endl;
        optimalBSTArray[i].printRootTable();
        std::cout << std::endl;
    }

    return 0;
}
