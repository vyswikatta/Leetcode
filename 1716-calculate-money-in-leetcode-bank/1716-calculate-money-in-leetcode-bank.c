int totalMoney(int n) {
    int total = 0;
    int monday = 1;

    for (int day = 1; day <= n; day++) {
        int weekDay = (day - 1) % 7;

        total += monday + weekDay;

        if (weekDay == 6) {
            monday++;
        }
    }

    return total;
}