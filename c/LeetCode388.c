/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int countOne(int n){
    int i;
    int counter = 0;
    for (i = 20; i >= 0; i--){ // assuming 20 bit integer (0 <= n <= 10^5)
        if (pow(2, i) <= n){
            counter++;
            n = n - pow(2, i);
        }
    }
    return counter;
}

int* countBits(int n, int* returnSize) {
    int* p = (int*)malloc((n+1)*sizeof(int));
    for (int i = 0; i <= n; i++){
        p[i] = countOne(i);
    }

    *returnSize = n + 1; // Update the returnSize
    return p;
}