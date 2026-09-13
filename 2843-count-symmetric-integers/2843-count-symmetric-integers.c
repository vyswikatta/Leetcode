int countSymmetricIntegers(int low, int high) {
    int count = 0;

    for (int x = low; x <= high; x++) {
        int temp = x;
        int digits = 0;

        // Count digits
        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        // Odd number of digits cannot be symmetric
        if (digits % 2 != 0)
            continue;

        int half = digits / 2;
        int leftSum = 0;
        int rightSum = 0;

        temp = x;

        // Sum right half
        for (int i = 0; i < half; i++) {
            rightSum += temp % 10;
            temp /= 10;
        }

        // Sum left half
        for (int i = 0; i < half; i++) {
            leftSum += temp % 10;
            temp /= 10;
        }

        if (leftSum == rightSum)
            count++;
    }

    return count;
}