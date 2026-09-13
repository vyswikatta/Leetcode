#include <stdlib.h>
#include <math.h>

int* closestDivisors(int num, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;

    int bestA = 1;
    int bestB = num + 1;
    int bestDiff = bestB - bestA;

    for (int x = num + 1; x <= num + 2; x++) {
        int a = (int)sqrt(x);

        while (a > 0) {
            if (x % a == 0) {
                int b = x / a;
                int diff = b - a;

                if (diff < bestDiff) {
                    bestDiff = diff;
                    bestA = a;
                    bestB = b;
                }

                break;
            }
            a--;
        }
    }

    result[0] = bestA;
    result[1] = bestB;

    return result;
}