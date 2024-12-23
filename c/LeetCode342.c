bool isPowerOfFour(int n) {
    int tmp;
    for (int i = 0; i <= 31; i++){ // input is in -2^31 <= n <= 2^31 - 1
        if (pow(4, i) == n){
            return true;
        }
    }
    return false;
}