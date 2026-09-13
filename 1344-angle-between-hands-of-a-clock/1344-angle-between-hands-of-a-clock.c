double angleClock(int hour, int minutes) {
    // Minute hand moves 6 degrees per minute
    double minuteAngle = minutes * 6.0;

    // Hour hand moves 30 degrees per hour
    // and 0.5 degrees per minute
    double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;

    double angle = fabs(hourAngle - minuteAngle);

    // Choose the smaller angle
    if (angle > 180.0) {
        angle = 360.0 - angle;
    }

    return angle;
}