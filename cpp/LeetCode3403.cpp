class Solution {
    public:
        string answerString(string word, int numFriends) {
            if (numFriends == 1) {
                return word;
            }
            
            int max_len = word.length() - numFriends + 1;
            string maxSubword = "";
            
            // Check all the word with the maximum len
            for (int i = 0; i < numFriends; i++) {
                string w = word.substr(i, max_len);
                if (w > maxSubword) {
                    maxSubword = w;
                }
            }
            
            // Check words with not maximum len that are at the end of the string
            for (int i = 1; i < max_len; i++) {
                string w = word.substr(word.length() - i);
                if (w > maxSubword) {
                    maxSubword = w;
                }
            }
            
            return maxSubword;
        }
    };