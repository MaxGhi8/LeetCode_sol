class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans = {1};
        int num = 1;
        int n_digits = 1;
        for (int i = 1; i < 6; i++) {
            if (n / (std::pow(10, i)) >= 1) {
                n_digits++;
                num *= 10;
                ans.push_back(num);
            }
        }

        int flag = 0;
        for (int i = 0; i < n-n_digits; i++) {
            if (flag > 0) {
                flag--;
                num *= 10;
            } else {
                num++;

                if (num > n) {
                    if (num % 10 == 0) {
                        num = num / 10;
                    } else {
                        num = num / 10 + 1;
                    }
                }
                while (num % 10 == 0) {
                    flag++;
                    num = num / 10;
                }

            }
            ans.push_back(num);
        }

        return ans;
    }
};