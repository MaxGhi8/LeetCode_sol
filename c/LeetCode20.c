#include <stdio.h>
#include <string.h>
bool isValid(char* s) {
    if (strlen(s) == 0) {
            return true;
        }
    int count = 0;
    int stack_idx = -1;
    char* stack = malloc(strlen(s)*sizeof(char));
    while (count < strlen(s)) {
        if (s[count] == '(' || s[count] == '[' || s[count] == '{') {
            stack_idx++;
            stack[stack_idx] = s[count];
            count++;
        } else {
            if (stack_idx == -1) {
                return false;
            }
            else if ((s[count] == ')' && stack[stack_idx] == '(') || (s[count] == ']' && stack[stack_idx] == '[') || (s[count] == '}' && stack[stack_idx] == '{')) {
            count++;
            stack_idx--; 

            } else {
                return false;
            }
        }
    }
    if (stack_idx == -1) {
        return true;
    } else {
        return false;
    }
    free(stack);
}