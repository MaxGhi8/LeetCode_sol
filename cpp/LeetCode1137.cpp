class Solution {
    public:
        int tribonacci(int n) {
            if (n == 0 || n == 1) {
                return n;
            } else if (n == 2) {
                return 1;
            }
            int fib_i_2 = 0;
            int fib_i_1 = 1;
            int fib_i = 1;
            int tmp;
            for (int i = 3; i <= n; i++) {
                tmp = fib_i;
                fib_i += fib_i_1 + fib_i_2;
                fib_i_2 = fib_i_1;
                fib_i_1 = tmp;
            }
            return fib_i;
        }
    };