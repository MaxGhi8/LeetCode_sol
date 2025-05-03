class Solution {
    public:
        bool isThree(int n) {
            int m = floor(sqrt(n));
            if ((m*m == n) && (isPrime(m))) {
                return true;
            } 
            return false;
        }
    
        bool isPrime(int m){
            if (m <= 1) {
                return false;
            }
            for (int i=2; i*i<=m; i++) {
                if (m % i == 0){
                    return false;
                }
             }
            return true;
        }
    };