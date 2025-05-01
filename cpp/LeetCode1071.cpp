class Solution {
    public:
        // Brute Force solution
        // string gcdOfStrings(string str1, string str2) {
        //         string test;
        //         int n1 = str1.size();
        //         int n2 = str2.size();
        //         if (n1 < n2) {
        //             test = str1;
        //         } else {
        //             test = str2;
        //         }
        
        //         for (int i = test.size(); i > 0; i--) {
        //             string temp = test.substr(0, i);
        //             int n = temp.size();
        //             if ((str1 == repeat(temp, n1/n)) && (str2 == repeat(temp, n2/n))) {
        //                 return temp;
        
        //             }
        //         }
        
        //         return "";
        //     }
        
        // private:
        //     string repeat(string s, int n) 
        //     { 
        //         string s1 = s; 
        //         for (int i=1; i<n; i++) 
        //             s += s1;
        
        //         return s; 
        //     } 
    
        // Math Solution
        string gcdOfStrings(string str1, string str2) {
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1) {
            return "";
        }
    
        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
        }
    };