class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // Construct the difference array
        vector<int> D = {};
        D.reserve(n);
        D[0] = nums[0];
        for (int i = 1; i < n; i++) {
            D[i] = nums[i] - nums[i-1];
        }

        // Update queries
        for (vector<int> q : queries) {
            D[q[0]]--;
            if (q[1] + 1 < n) {
                D[q[1]+1]++;
            }
        }

        // Go back to nums with prefix sum and check condition
        if (D[0] > 0) {
            return false;
        }
        for (int i = 1; i < n; i++) {
            D[i] = D[i] + D[i-1];
            if (D[i] > 0) {
                return false;
            }
        }

        return true;
        
    }
};