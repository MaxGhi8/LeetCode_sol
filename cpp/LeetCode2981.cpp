class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        vector<long long> num_zeros = {0, 0};
        vector<long long> min_sum = {0, 0};

        // read nums1
        for (int n : nums1) {
            if (n == 0){
                num_zeros[0] += 1;
                min_sum[0] += 1;
            } else {
                min_sum[0] += n;
            }
        }
        // read nums2
        for (int n : nums2) {
            if (n == 0){
                num_zeros[1] += 1;
                min_sum[1] += 1;
            } else {
                min_sum[1] += n;
            }
        }

        if (num_zeros[0] * num_zeros[1] != 0) { // both have zeros
            return std::max(min_sum[0], min_sum[1]);
        } 
        if (num_zeros[0] + num_zeros[1] == 0) { // no zeros present
            if (min_sum[0] == min_sum[1]) {
                return min_sum[0];
            } else {
                return -1;
            }
        }
        // only one is zero
        if (num_zeros[0] == 0) {
            if (min_sum[1] <= min_sum[0]) {
                return min_sum[0];
            } else {
                return -1;
            }
        }
        if (num_zeros[1] == 0) {
            if (min_sum[0] <= min_sum[1]) {
                return min_sum[1];
            } else {
                return -1;
            }
        }

        return -1;
    }
};