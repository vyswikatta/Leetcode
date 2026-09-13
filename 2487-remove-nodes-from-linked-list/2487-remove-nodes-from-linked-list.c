struct ListNode* removeNodes(struct ListNode* head) {
    
    // Reverse the list
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    // Remove nodes smaller than the maximum seen so far
    int maxVal = 0;
    curr = head;
    prev = NULL;

    while (curr != NULL) {
        if (curr->val >= maxVal) {
            maxVal = curr->val;
            prev = curr;
            curr = curr->next;
        } else {
            prev->next = curr->next;
            curr = curr->next;
        }
    }

    // Reverse back
    prev = NULL;
    curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}