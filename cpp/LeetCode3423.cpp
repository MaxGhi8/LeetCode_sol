class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max_ = std::abs(nums[0] - nums[nums.size()-1]);

        for (int i = 0; i < nums.size()-1; i++) {
            int diff = std::abs(nums[i] - nums[i+1]);
            if (diff > max_) {
                max_ = diff;
            }
        }
        return max_;
    }
};