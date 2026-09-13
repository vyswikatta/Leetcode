char* reversePrefix(char* word, char ch) {
    int end = 0;

    // Find the first occurrence of ch
    while (word[end] != '\0' && word[end] != ch) {
        end++;
    }

    // If ch is not found, return the original string
    if (word[end] == '\0') {
        return word;
    }

    // Reverse from 0 to end
    int start = 0;

    while (start < end) {
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;

        start++;
        end--;
    }

    return word;
}