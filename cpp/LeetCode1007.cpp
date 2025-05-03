class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            const int n = tops.size();
    
            const int n1 = tops[0];
            const int n2 = bottoms[0];  
            int n1_total = 1;
            int n1_top = 1;
            int n1_bottom = 0;
            int n2_total = 1;
            int n2_top = 0;
            int n2_bottom = 1;
    
            for (int i=1; i<n; i++) {
                // Check feasibility
                if ( (tops[i] != n1 && bottoms[i] != n1) && (tops[i] != n2 && bottoms[i] != n2) ) {
                    return -1;
                }
                // Update quantities
                if (tops[i] == n1 || bottoms[i] == n1){
                    n1_total++;
                    if (tops[i] == n1) {
                        n1_top++;
                    } 
                    if (bottoms[i] == n1){
                        n1_bottom++;
                    }
                }
                if (tops[i] == n2 || bottoms[i] == n2){
                    n2_total++;
                    if (tops[i] == n2) {
                        n2_top++;
                    } 
                    if (bottoms[i] == n2){
                        n2_bottom++;
                    }
                }
            }
    
            int n1_out = n;
            int n2_out = n;
            if (n1_total == n){
                n1_out = std::min(n - n1_bottom, n - n1_top);
            }
            if (n2_total == n){
                n2_out = std::min(n - n2_bottom, n - n2_top);
            }
    
            int output = std::min(n1_out, n2_out);
            if (output < n) {
                return output;
            } else {
                return -1;
            }
    
        }
    };