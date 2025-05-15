class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int bit = -1;

        for (int i = 0; i < words.size(); i++){
            if (groups[i] != bit){
                result.push_back(words[i]);
                bit = groups[i];
            }
        }
        
        return result;
    }
};