class Solution {
    public:
        bool canAliceWin(vector<int>& nums) {
            int alice = 0;
            int bob = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= 9) {
                    alice += nums[i]; 
                } else {
                    bob += nums[i];
                }
            }
            if (bob == alice) {
                return false;
            } else {
                return true;
            }
        }
    };