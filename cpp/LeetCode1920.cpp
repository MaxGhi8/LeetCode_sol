class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            vector<int> ans = nums;
            if (nums.size() <= 1) {
                return ans;
            } 
            for (int i=0; i<nums.size(); i++){
                ans[i] = nums[nums[i]];
            }
            return ans;
        }
    };