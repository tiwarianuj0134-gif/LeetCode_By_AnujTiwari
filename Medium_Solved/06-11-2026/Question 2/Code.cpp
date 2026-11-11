class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            // Detect duplicates.
            if (curr->next && curr->val == curr->next->val) {
                int duplicate = curr->val;

                // Skip all occurrences.
                while (curr && curr->val == duplicate) {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
