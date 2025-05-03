class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int num;
            int count;
            int j;
            int result = 0;
            for (int i = 0; i < nums.size(); i++) {
                num = nums[i];
                count = 1;
                j = 1;
                // Count the number of digit
                while (true) {
                    if (num - pow(10, j) >= 0) {
                        count ++;
                        j++;
                    } else {
                        break;
                    }
                }
                if (count % 2 == 0) {
                    result++;
                }
            }
            return result;
        }
    };