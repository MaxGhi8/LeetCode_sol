#include <iostream>

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};


// better solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> alpha;
        for (char c : s){
            alpha[c]++;
        }
        for (char c : t){
            alpha[c]--;
        }

        for (const auto & [_, n] : alpha) {
            if (n != 0) {
                return false;
            }
        }
        return true;

    }
};