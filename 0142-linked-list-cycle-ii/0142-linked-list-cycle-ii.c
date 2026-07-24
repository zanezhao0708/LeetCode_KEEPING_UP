/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//由于 (kc−a)+a=kc，所以从 kc−a 开始，再走 a 步，就恰好走了 k 圈，回到入环口
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
