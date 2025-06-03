class Solution {
    public:
        int differenceOfSums(int n, int m) {
            int ans = (n*(n+1))/2;
            int k = n/m;
            for (int i = 1; i <= k; i++) {
                ans -= 2*(m*i);
            }
            return ans;
        }
    };