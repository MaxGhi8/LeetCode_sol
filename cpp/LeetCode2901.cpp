class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = size(words);
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int max_index = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkHamming(words[i], words[j]) && groups[i] != groups[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                    if (dp[i] > dp[max_index]){
                        max_index = i;
                    }
                }
            }
        }

        vector<string> ans;
        for (int i = max_index; i > -1; i = prev[i]) {
            ans.emplace_back(words[i]);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool checkHamming(string v, string w) {
        return hammingDistance(v, w) == 1;
    }

    int hammingDistance(string v, string w) {
        if (v.size() != w.size()) {
            return -1;
        } 
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != w[i]) {
                count++;
            }
        }
        return count;
    }
};