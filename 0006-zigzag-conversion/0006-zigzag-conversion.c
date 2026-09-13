#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    // Special case
    if (numRows == 1 || numRows >= len) {
        char* result = malloc(len + 1);
        strcpy(result, s);
        return result;
    }

    // Create space for each row
    char** rows = malloc(numRows * sizeof(char*));

    for (int i = 0; i < numRows; i++) {
        rows[i] = malloc((len + 1) * sizeof(char));
        rows[i][0] = '\0';
    }

    int row = 0;
    int direction = 1;

    // Put each character into its zigzag row
    for (int i = 0; i < len; i++) {
        int currentLen = strlen(rows[row]);
        rows[row][currentLen] = s[i];
        rows[row][currentLen + 1] = '\0';

        // Change direction at top and bottom
        if (row == numRows - 1)
            direction = -1;
        else if (row == 0)
            direction = 1;

        row += direction;
    }

    // Combine all rows
    char* result = malloc(len + 1);
    int index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; rows[i][j] != '\0'; j++) {
            result[index++] = rows[i][j];
        }
    }

    result[index] = '\0';

    // Free memory
    for (int i = 0; i < numRows; i++) {
        free(rows[i]);
    }
    free(rows);

    return result;
}