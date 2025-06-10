class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> Ds;
        for (char c : s) {
            Ds[c]++;
        }
        
        int min_ = 100;
        int max_ = 0;
        for (auto i : Ds) {
            if (i.second % 2 == 1 && i.second > max_) {
                max_ = i.second;
            } 
            if (i.second % 2 == 0 && i.second < min_) {
                min_ = i.second;
            }
        }
        
        return max_ - min_;
    }
};