int** transpose(int** matrix, int matrixSize, int* matrixColSize,
                int* returnSize, int** returnColumnSizes) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    // New matrix will have cols rows
    int** result = malloc(cols * sizeof(int*));

    *returnSize = cols;

    *returnColumnSizes = malloc(cols * sizeof(int));

    for (int i = 0; i < cols; i++) {
        result[i] = malloc(rows * sizeof(int));
        (*returnColumnSizes)[i] = rows;
    }

    // Transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}