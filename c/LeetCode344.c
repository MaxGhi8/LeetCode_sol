void reverseString(char* s, int sSize) {
    for (int i = 0; i < sSize; i++){
        int j = sSize - i - 1;
        
        if (i >= j){
            break;
        } else {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }

    }
}