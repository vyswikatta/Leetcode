int minOperations(char** logs, int logsSize) {
    int depth = 0;

    for (int i = 0; i < logsSize; i++) {

        if (strcmp(logs[i], "../") == 0) {
            // Go to parent folder
            if (depth > 0) {
                depth--;
            }
        }
        else if (strcmp(logs[i], "./") == 0) {
            // Stay in the same folder
            continue;
        }
        else {
            // Enter a child folder
            depth++;
        }
    }

    return depth;
}