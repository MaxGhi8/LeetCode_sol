bool isVowel(char c) {
    c = tolower(c); // Convert to lowercase
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char* reverseVowels(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (isVowel(s[left]) && isVowel(s[right])) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
            continue;
        }
        if (! isVowel(s[left])) {
            left++;
        }
        if (! isVowel(s[right])) {
            right--;
        }
    }

    return s;
}