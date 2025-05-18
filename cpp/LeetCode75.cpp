class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> idx = {-1, -1, -1};
        for (int n : nums){
            if (n == 0) {
                idx[0]++;
                idx[1]++;
                idx[2]++;
                nums[idx[2]] = 2;
                nums[idx[1]] = 1;
                nums[idx[0]] = 0;
            } else if (n == 1) {
                idx[1]++;
                idx[2]++;
                nums[idx[2]] = 2;
                nums[idx[1]] = 1;
            } else {
                idx[2]++;
                nums[idx[2]] = 2;
            }
        }
    }
};