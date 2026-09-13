int maxSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int maxSum = 0;

    for (int i = 0; i <= m - 3; i++) {
        for (int j = 0; j <= n - 3; j++) {

            int sum = 0;

            // Top row: 3 elements
            sum += grid[i][j];
            sum += grid[i][j + 1];
            sum += grid[i][j + 2];

            // Middle: 1 element
            sum += grid[i + 1][j + 1];

            // Bottom row: 3 elements
            sum += grid[i + 2][j];
            sum += grid[i + 2][j + 1];
            sum += grid[i + 2][j + 2];

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }

    return maxSum;
}