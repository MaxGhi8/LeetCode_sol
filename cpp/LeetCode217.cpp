class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> seen;
        for (int n : nums) {
            if (seen[n] >= 1){
                return true;
            }
            seen[n]++;
        }
        return false;
    }
};