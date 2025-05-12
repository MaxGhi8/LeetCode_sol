class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // maps of frequency
        std::unordered_map<int, int> freq;
        for (int n : digits){
            freq[n]++;
        }
        // list of output
        std::vector<int> result;
        for (int i=1; i<10; i++){
            if (freq.find(i) == freq.end() || freq[i] == 0){
                continue;
            }
            freq[i]--;
            for (int j=0; j<10; j++){
                if (freq.find(j) == freq.end() || freq[j] == 0){
                    continue;
                }
                freq[j]--;

                for (int k : {0, 2, 4, 6, 8}){
                    if (freq.find(k) == freq.end() || freq[k] == 0){
                        continue;
                    }
                    result.push_back(100*i + 10*j + k);
    
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return result;
    }
};