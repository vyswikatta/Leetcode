int minLength(char* s) {
    char stack[105];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (top >= 0 &&
            ((stack[top] == 'A' && ch == 'B') ||
             (stack[top] == 'C' && ch == 'D'))) {
            
            // Remove "AB" or "CD"
            top--;
        } else {
            // Add character to stack
            stack[++top] = ch;
        }
    }

    return top + 1;
}