class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
       std::sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums[nums.size()-1] - nums[0];

        while (left < right) {
            int mid = left + (right - left)/2;
            int counter = count(mid, nums);
            if (counter >= p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;

    }

    // Comparator function
    bool comp(int a, int b) {
        return a > b;
    }

    int count(int treshold, vector<int>& nums) {
        int ans = 0;
        int i = 0;
        while (i < nums.size() - 1) {
            if (nums[i+1] - nums[i] <= treshold) {
                i++;
                ans++;
            }
            i++;
        }
        return ans;
    }

};