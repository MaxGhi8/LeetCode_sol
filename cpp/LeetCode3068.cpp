class Solution {
    public:
        long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
            long long ans = 0;
            int min_delta = 1000000000;
            int count = 0;
    
            for (int i = 0; i < nums.size(); i++) {
                int n = nums[i];
                int m = n ^ k;
                int delta = m-n;
    
                if (delta > 0) {
                    ans += m;
                    count = (count + 1) % 2;
                    if (delta < min_delta) {
                        min_delta = delta;
                    }
                } else {
                    ans += n;
                    if (-delta < min_delta) {
                        min_delta = -delta;
                    }
                }
            }
    
            if (count == 0) {
                return ans;
            } else {
                return ans - min_delta;
            }
            
        }
    };