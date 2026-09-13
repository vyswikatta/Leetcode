char* removeOuterParentheses(char* s) {
    int n = strlen(s);

    char* result = malloc((n + 1) * sizeof(char));
    int balance = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {

        if (s[i] == '(') {
            // Add '(' only if it is not the outermost one
            if (balance > 0) {
                result[j++] = '(';
            }
            balance++;
        }
        else {
            balance--;

            // Add ')' only if it is not the outermost one
            if (balance > 0) {
                result[j++] = ')';
            }
        }
    }

    result[j] = '\0';

    return result;
}