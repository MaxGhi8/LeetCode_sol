class Solution {
public:
    int candy(vector<int>& ratings) {
        // Initialization
        int n = ratings.size();
        int ans = 0;
        int n_inc = 0;
        int n_dec = 0;
        int equal = 0;
        int succ;
        int flag_equal = 0;
        int last_max = 0;

        for (int i = 0; i < n; i++) {
            if (i == n-1) {
                succ = ratings[n-1];
            } else {
                succ = ratings[i+1];
            }

            if (ratings[i] < succ) {
                // increasing sequence
                n_inc++;
                if (n_dec > 0) {
                    ans += makeSum(n_dec+1) -1- min(last_max, n_dec+1);
                    n_dec = 0;
                    last_max = 0;
                }
                if (equal > 1) {
                    ans += equal-1;
                }
                equal = 0;
            } else if (ratings[i] > succ) {
                // decreasing sequence
                n_dec++;
                if (n_inc > 0) {
                    last_max = n_inc+1;
                    ans += makeSum(n_inc+1);
                    n_inc = 0;
                }
                if (equal > 1) {
                    ans += equal-1;
                }
                equal = 0;
            } else {
                // constant sequence
                equal++;
                if (n_dec > 0) {
                    ans += makeSum(n_dec+1) - min(last_max, n_dec+1);
                    last_max = 0;
                    n_dec = 0;
                } else if (n_inc > 0) {
                    ans += makeSum(n_inc+1); 
                    n_inc = 0;
                }
                if (i == 0) {
                    flag_equal++;
                }
            }

        }

        return ans + equal - 1 + flag_equal;
    }

    int makeSum(int n) {
        if (n == 1) {
            return 0;
        }
        return (n*(n+1))/2;
    }

};