/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) { // 相遇
            while (slow != head) { // 再走 a 步
                slow = slow->next;
                head = head->next;
            }
            return slow;
        }
    }
    return NULL;
}
