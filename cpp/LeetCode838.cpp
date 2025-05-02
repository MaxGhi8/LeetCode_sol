class Solution {
    public:
        string pushDominoes(string dominoes) {
            const int n = dominoes.size();
            vector<int> As(n);
    
            // travers the string forward
            int flag = -1;
            for (int i=0; i<n; i++) {
                if (dominoes[i] == 'R') {
                    flag = 0;
                } else if (dominoes[i] == 'L') {
                    flag = -1;
                } else if (flag != -1) {
                    As[i] = As[i] + n - flag;
                    flag++;
                }
            }
            // cout << "Array elements: ";
            // for (int i = 0; i < n; i++) {
            //     cout << As[i] << " ";
            // }
            // cout << endl;
    
            // Travers the string backward
            flag = -1;
            for (int i = n-1; i>=0; i--) {
                if (dominoes[i] == 'L') {
                    flag = 0;
                } else if (dominoes[i] == 'R') {
                    flag = -1;
                } else if (flag != -1) {
                    As[i] = As[i] - (n - flag);
                    flag++;
                }
            }
            // cout << "Array elements: ";
            // for (int i = 0; i < n; i++) {
            //     cout << As[i] << " ";
            // }
            // cout << endl;
    
            // Update string
            for (int i=0; i<n; i++){
                if (As[i] > 0) {
                    dominoes[i] = 'R';
                } else if (As[i] < 0){
                    dominoes[i] = 'L';
                }
            }
    
            return dominoes;
    
        }
    };