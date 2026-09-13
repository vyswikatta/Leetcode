int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
    int maxRow = 0;
    int maxOnes = 0;

    for (int i = 0; i < matSize; i++) {
        int count = 0;

        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) {
                count++;
            }
        }

        if (count > maxOnes) {
            maxOnes = count;
            maxRow = i;
        }
    }

    int* result = malloc(2 * sizeof(int));
    result[0] = maxRow;
    result[1] = maxOnes;

    *returnSize = 2;

    return result;
}