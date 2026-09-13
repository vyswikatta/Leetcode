int** largestLocal(int** grid, int gridSize, int* gridColSize,
                   int* returnSize, int** returnColumnSizes) {

    int n = gridSize;
    int size = n - 2;

    int** result = malloc(size * sizeof(int*));
    *returnSize = size;

    *returnColumnSizes = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        result[i] = malloc(size * sizeof(int));
        (*returnColumnSizes)[i] = size;

        for (int j = 0; j < size; j++) {

            int max = 0;

            // Check the 3 x 3 area
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    if (grid[x][y] > max) {
                        max = grid[x][y];
                    }
                }
            }

            result[i][j] = max;
        }
    }

    return result;
}