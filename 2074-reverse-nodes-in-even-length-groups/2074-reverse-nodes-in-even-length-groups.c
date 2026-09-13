struct ListNode* reverseEvenLengthGroups(struct ListNode* head) {
    struct ListNode* prevGroupEnd = NULL;
    struct ListNode* curr = head;
    int groupSize = 1;

    while (curr != NULL) {
        struct ListNode* groupStart = curr;
        struct ListNode* temp = curr;
        int count = 0;

        // Find the actual size of the current group
        while (temp != NULL && count < groupSize) {
            temp = temp->next;
            count++;
        }

        // If group size is even, reverse it
        if (count % 2 == 0) {
            struct ListNode* prev = temp;
            curr = groupStart;

            for (int i = 0; i < count; i++) {
                struct ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous group to reversed group
            if (prevGroupEnd != NULL) {
                prevGroupEnd->next = prev;
            } else {
                head = prev;
            }

            prevGroupEnd = groupStart;
        } else {
            // No reversal
            curr = temp;
            prevGroupEnd = groupStart;

            for (int i = 1; i < count; i++) {
                prevGroupEnd = prevGroupEnd->next;
            }
        }

        groupSize++;
    }

    return head;
}