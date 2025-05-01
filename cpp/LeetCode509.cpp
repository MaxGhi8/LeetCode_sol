class Solution {
    public:
        // Not efficient for the stack
        // int fib(int n) {
        //     if (n == 0 || n == 1) {
        //         return n;
        //     } else {
        //         return fib(n-1) + fib(n-2);
        //     }
        // }
    
        // Efficient solution
        int fib(int n) {
            if (n == 0 || n == 1) {
                return n;
            }
            int fib_i_1 = 0;
            int fib_i = 1;
            int tmp;
            for (int i = 2; i <= n; i++) {
                tmp = fib_i;
                fib_i += fib_i_1;
                fib_i_1 = tmp;
            }
            return fib_i;
        }
    };