class Solution {
    public:
        string triangleType(vector<int>& nums) {
        // Check if triangle inequality is satisfied
        if (nums[0] + nums[1] <= nums[2] || 
            nums[1] + nums[2] <= nums[0] || 
            nums[0] + nums[2] <= nums[1]) {
            return "none";
        }
        
        // Check if all sides are equal
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        
        // Check if any two sides are equal
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        }
        
        // Otherwise, it's a scalene triangle
        return "scalene";
        }i
    };