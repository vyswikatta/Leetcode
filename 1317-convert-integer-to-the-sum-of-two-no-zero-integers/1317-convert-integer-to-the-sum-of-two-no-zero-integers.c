#include <stdlib.h>

/* Check whether a number contains digit 0 */
int isNoZero(int num) {
    while (num > 0) {
        if (num % 10 == 0)
            return 0;

        num /= 10;
    }

    return 1;
}

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */
int* getNoZeroIntegers(int n, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));

    for (int a = 1; a < n; a++) {
        int b = n - a;

        if (isNoZero(a) && isNoZero(b)) {
            result[0] = a;
            result[1] = b;

            *returnSize = 2;
            return result;
        }
    }

    *returnSize = 0;
    free(result);

    return NULL;
}