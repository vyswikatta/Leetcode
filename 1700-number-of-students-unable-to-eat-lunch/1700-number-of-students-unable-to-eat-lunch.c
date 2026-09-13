  int countStudents(int* students, int studentsSize,
                  int* sandwiches, int sandwichesSize) {
    
    int count[2] = {0, 0};

    // Count how many students prefer each type
    for (int i = 0; i < studentsSize; i++) {
        count[students[i]]++;
    }

    // Process sandwiches from the top
    for (int i = 0; i < sandwichesSize; i++) {
        
        int type = sandwiches[i];

        // Nobody wants this sandwich
        if (count[type] == 0) {
            break;
        }

        // One student takes it
        count[type]--;
    }

    return count[0] + count[1];
}