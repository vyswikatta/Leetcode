#include <stdbool.h>
#include <string.h>

bool arrayStringsAreEqual(char** word1, int word1Size,
                          char** word2, int word2Size) {

    int i = 0, j = 0;
    int p = 0, q = 0;

    while (i < word1Size && j < word2Size) {

        // Compare current characters
        if (word1[i][p] != word2[j][q]) {
            return false;
        }

        p++;
        q++;

        // Move to next string in word1
        if (word1[i][p] == '\0') {
            i++;
            p = 0;
        }

        // Move to next string in word2
        if (word2[j][q] == '\0') {
            j++;
            q = 0;
        }
    }

    // Both arrays must be completely consumed
    return i == word1Size && j == word2Size;
}