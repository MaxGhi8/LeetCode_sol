class Solution {
    public:
        int findGCD(vector<int>& nums) {
            int minVal = 1000;
            int maxVal = 0;
            
            // Find minimum and maximum values
            for (int i = 0; i < nums.size(); i++) {
                minVal = min(minVal, nums[i]);
                maxVal = max(maxVal, nums[i]);
            }
            
            // Calculate GCD of min and max
            return gcd(minVal, maxVal);
        }
    
    private:
        int gcd(int a, int b) {
            while (b) {
                int tmp = a % b;
                a = b;
                b = tmp;
            }
            return a;
        }
    };