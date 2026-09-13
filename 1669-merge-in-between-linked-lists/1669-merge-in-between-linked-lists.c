struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b,
                                struct ListNode* list2) {
    
    struct ListNode* before = list1;
    
    // Move to the node just before index a
    for (int i = 0; i < a - 1; i++) {
        before = before->next;
    }

    struct ListNode* after = before->next;
    
    // Move to the node just after index b
    for (int i = a; i <= b; i++) {
        after = after->next;
    }

    // Connect list1 before a to list2
    before->next = list2;

    // Find the last node of list2
    struct ListNode* last = list2;
    while (last->next != NULL) {
        last = last->next;
    }

    // Connect list2 to the part after b
    last->next = after;

    return list1;
}