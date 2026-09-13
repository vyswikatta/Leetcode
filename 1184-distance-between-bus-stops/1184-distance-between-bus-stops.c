int distanceBetweenBusStops(int* distance, int distanceSize,
                            int start, int destination) {
    
    // Make sure start comes before destination
    if (start > destination) {
        int temp = start;
        start = destination;
        destination = temp;
    }

    int clockwise = 0;
    int total = 0;

    // Calculate total distance around the circle
    for (int i = 0; i < distanceSize; i++) {
        total += distance[i];
    }

    // Distance from start to destination
    for (int i = start; i < destination; i++) {
        clockwise += distance[i];
    }

    // Other direction
    int counterclockwise = total - clockwise;

    return (clockwise < counterclockwise) ? clockwise : counterclockwise;
}