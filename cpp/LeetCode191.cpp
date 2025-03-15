#include <iostream>
#include <cmath>

class Solution {
public:
    int hammingWeight(int n) {
        // find max power of 2
        int max_power;
        for (int i = 30; i >= 0; i--){
            if (std::pow(2, i) <= n){
                max_power = i;
                break;
            }
        }

        // compute the number of ones in the binary representation
        int acc = 0;
        for (int i = max_power; i>=0; i--){
            if (std::pow(2, i) <= n){
                acc++;
                n = n - pow(2, i);
            }
        }

        return acc;
    }
};