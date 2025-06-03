class Solution {
    public:
        int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
            int ans = 0;
            unordered_set<int> openBoxes = {};
            unordered_set<int> closedBoxes = {};
            unordered_set<int> obtainedKeys = {};
    
            // initialize open and closed Boxes 
            for (int i = 0; i < initialBoxes.size(); i++) {
                if (status.at(initialBoxes.at(i)) == 1) {
                    openBoxes.insert(initialBoxes.at(i));
                } else {
                    closedBoxes.insert(initialBoxes.at(i));
                }
            }
    
            // Loop over openBoxes
            while (!openBoxes.empty()) {
                // Take a box
                int box = *openBoxes.begin();
                openBoxes.erase(box);
    
                // Looks for candies
                ans += candies.at(box);
    
                // Looks for keys
                vector<int> key = keys.at(box);
                for (int i = 0; i < key.size(); i++) {
                    int k = key.at(i);
                    if (closedBoxes.find(k) != closedBoxes.end()) {
                        closedBoxes.erase(k);
                        openBoxes.insert(k);
                    } else {
                        obtainedKeys.insert(k);
                    }
                }
    
                // Look for other Boxes
                vector<int> subBoxes = containedBoxes.at(box);
                for (int i = 0; i < subBoxes.size(); i++) {
                    int b = subBoxes.at(i);
                    if (status.at(b) == 1) {
                        openBoxes.insert(b);
                    } else {
                        if (obtainedKeys.find(b) != obtainedKeys.end()) {
                            obtainedKeys.erase(b);
                            openBoxes.insert(b);
                        } else {
                            closedBoxes.insert(b);
                        }
                    }
                }
    
            }
    
            return ans;
    
        }
    };