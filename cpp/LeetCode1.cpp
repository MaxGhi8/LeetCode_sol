#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered_map to store the number as key and its index as value
        std::unordered_map<int, int> dict_nums;
        
        // Fill the map with values from nums
        int len_ = nums.size();
        for (int idx = 0; idx < len_; ++idx) {
            dict_nums[nums[idx]] = idx;
        }

        // Iterate through the nums array
        for (int idx = 0; idx < len_; ++idx) {
            int num = nums[idx];
            if (dict_nums[num] == idx) {
                dict_nums.erase(num);  // Remove the current number from the map
            }
            // Check if the complement (target - num) exists in the map
            int complement = target - num;
            if (dict_nums.find(complement) != dict_nums.end()) {
                return {idx, dict_nums[complement]};  // Return the indices
            }
        }

        // Return empty if no solution found (this line is theoretically unreachable if the problem guarantees a solution)
        return {};
    }
};