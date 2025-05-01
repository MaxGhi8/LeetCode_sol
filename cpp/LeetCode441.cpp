class Solution {
    public:
        int arrangeCoins(int n) {
            return std::floor((std::sqrt(1 + (long long int) 8*n)-1)/2);
        }
    };