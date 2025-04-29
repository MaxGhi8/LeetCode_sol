#include <set>
#include <string>

class Solution {
public:
    bool isHappy(int n) {
        std::set<int> loop;
        while (true) {
            n = convert(n);
            if (n == 1) {
                return true;
            }
            if (loop.find(n) != loop.end()) {
                return false;
            } else {
                loop.insert(n);
            }
        }
    }

    int convert(int n) {
        std::string n_str = std::to_string(n);
        int sum = 0;
        for (int i = 0; i < n_str.length(); i++) {
            int digit = n_str[i] - '0';
            sum += std::pow(digit, 2);
        }
        return sum;
    }
};