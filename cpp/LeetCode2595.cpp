class Solution {
    public:
        vector<int> evenOddBit(int n) {
            vector<int> output = {0, 0};
            for (int i = 9; i >= 0; i--) {
                if (n - pow(2, i) >= 0) {
                    n -= pow(2, i);
                    if (i % 2 == 0) {
                        output[0] += 1;
                    } else {
                        output[1] += 1;
                    }
                }
            }
            return output;
        }
    };