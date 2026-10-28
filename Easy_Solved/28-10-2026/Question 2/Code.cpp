class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseListRecursive(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* newHead = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
