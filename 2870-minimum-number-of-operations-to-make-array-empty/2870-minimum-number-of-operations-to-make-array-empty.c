int minOperations(int* nums, int numsSize) {
    int freq[1000001] = {0};
    int operations = 0;

    // Count frequency of each number
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    // Find minimum operations for each frequency
    for (int i = 1; i <= 1000000; i++) {
        if (freq[i] == 1) {
            return -1;
        }

        if (freq[i] > 0) {
            // Use groups of 3 as much as possible
            operations += freq[i] / 3;

            // If remainder is 1, replace one group of 3
            // with two groups of 2
            if (freq[i] % 3 == 1) {
                operations += 1;
            }
            // Remainder 2 needs one more operation
            else if (freq[i] % 3 == 2) {
                operations += 1;
            }
        }
    }

    return operations;
}