#include <stdlib.h>

struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    // Store prefix sum and the last node having that sum
    struct {
        int sum;
        struct ListNode* node;
    } map[2001];

    int mapSize = 0;
    int sum = 0;

    struct ListNode* curr = &dummy;

    // First pass: store the LAST node for each prefix sum
    while (curr != NULL) {
        sum += curr->val;

        int found = -1;

        for (int i = 0; i < mapSize; i++) {
            if (map[i].sum == sum) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            map[found].node = curr;
        } else {
            map[mapSize].sum = sum;
            map[mapSize].node = curr;
            mapSize++;
        }

        curr = curr->next;
    }

    // Second pass: connect each node to the last node
    // having the same prefix sum
    sum = 0;
    curr = &dummy;

    while (curr != NULL) {
        sum += curr->val;

        for (int i = 0; i < mapSize; i++) {
            if (map[i].sum == sum) {
                curr->next = map[i].node->next;
                break;
            }
        }

        curr = curr->next;
    }

    return dummy.next;
}