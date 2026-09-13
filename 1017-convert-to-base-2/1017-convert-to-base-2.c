char* baseNeg2(int n) {
    char* result = malloc(40 * sizeof(char));
    int index = 39;

    result[index] = '\0';

    if (n == 0) {
        result[--index] = '0';
        return &result[index];
    }

    while (n != 0) {
        int remainder = n % -2;
        n = n / -2;

        if (remainder < 0) {
            remainder += 2;
            n++;
        }

        result[--index] = remainder + '0';
    }

    return &result[index];
}