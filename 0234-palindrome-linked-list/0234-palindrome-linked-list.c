/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* left;

bool is_pal(struct ListNode* right) {
    // 「递」，先把 right 移到链表末尾
    if (right->next && !is_pal(right->next)) {
        return false;
    }
    // 「归」的过程就是在从右到左遍历链表
    if (left->val != right->val) {
        return false;
    }
    left = left->next; // left 往右走
    return true; // 归，right 会往左走
}

bool isPalindrome(struct ListNode* head) {
    left = head;
    return is_pal(head);
}
