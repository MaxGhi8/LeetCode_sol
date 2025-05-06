class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<int, int> dominoCount;
            
            for (const auto& domino : dominoes) {
                int a = domino[0];
                int b = domino[1];
                
                int key;
                if (a <= b) {
                    key = a * 10 + b;
                } else {
                    key = b * 10 + a;
                }
                
                dominoCount[key]++;
            }
            
            int result = 0;
            for (const auto& pair : dominoCount) {
                int count = pair.second;
                result += (count * (count - 1)) / 2;
            }
            
            return result;
        }
    };