#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // 1. Skip leading spaces
    while (s[i] == ' ') {
        i++;
    }

    // 2. Check sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } 
    else if (s[i] == '+') {
        i++;
    }

    // 3. Convert digits
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // 4. Check overflow before multiplication
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}