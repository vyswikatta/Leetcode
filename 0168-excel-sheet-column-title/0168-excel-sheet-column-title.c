char* convertToTitle(int columnNumber) {
    char* result = malloc(20 * sizeof(char));
    int index = 19;

    result[index] = '\0';

    while (columnNumber > 0) {
        columnNumber--;

        int remainder = columnNumber % 26;

        result[--index] = 'A' + remainder;

        columnNumber /= 26;
    }

    return &result[index];
}