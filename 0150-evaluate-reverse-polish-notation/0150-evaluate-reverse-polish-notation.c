#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {

        // If token is a number
        if (strcmp(tokens[i], "+") != 0 &&
            strcmp(tokens[i], "-") != 0 &&
            strcmp(tokens[i], "*") != 0 &&
            strcmp(tokens[i], "/") != 0) {

            stack[++top] = atoi(tokens[i]);
        }
        else {
            // Pop the second operand first
            int b = stack[top--];

            // Pop the first operand
            int a = stack[top--];

            int result;

            if (strcmp(tokens[i], "+") == 0)
                result = a + b;
            else if (strcmp(tokens[i], "-") == 0)
                result = a - b;
            else if (strcmp(tokens[i], "*") == 0)
                result = a * b;
            else
                result = a / b;

            // Push result back
            stack[++top] = result;
        }
    }

    return stack[top];
}