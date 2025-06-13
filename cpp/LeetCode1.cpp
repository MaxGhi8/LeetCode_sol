#include <unordered_map>
#include <vector>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> seen;
            for (int i = 0; i < nums.size(); i++) {
                int wanted_value = target - nums[i];
                
                if (seen.find(wanted_value) != seen.end()) {
                    return {i, seen[wanted_value]};
                }
    
                seen[nums[i]] = i;
            }
    
            return {};
        }
    };