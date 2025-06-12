class Solution {
    public:
        string robotWithString(string s) {
            const string alphabet = "abcdefghijklmnopqrstuvwxyz";
            map<char, int> D = {};
            string t = "";
            string ans = "";
    
            // preprocessing
            for (char c : s) {
                D[c]++;
            }
            
            int i = 0;
            while (i < s.size()) {
                char c_min = find_min(alphabet, D);
    
                // check in t
                if (t != "" && t.at(t.size()-1) <= c_min) {
                    ans.push_back(t.at(t.size()-1));
                    t.pop_back();
                    continue;
                }
    
                // looking for c_min
                for (int j = i; j < s.size(); j++) {
                    char c = s.at(j);
                    if (c == c_min) {
                        ans.push_back(c);
                        D[c]--;
                        i++;
                        break;
                    } else {
                        t.push_back(c);
                        D[c]--;
                        i++;
                    }
                }
            }
    
            // attach t
            for (int k = t.size()-1; k >= 0; k--) {
                ans.push_back(t.at(k));
            }
    
            return ans;
        }
    
        char find_min(string alphabet, map<char, int> D) {
            for (char c : alphabet) {
                if (D[c] > 0) {
                    return c;
                }
            }
            return 'z';
        }
    
    };