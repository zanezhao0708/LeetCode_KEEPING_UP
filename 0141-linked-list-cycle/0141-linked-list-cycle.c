/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head)return false;
    int count = 10000;
    while(count){
        if(head->next == NULL)return false;
        head = head->next;
        count--;
    }
    return true;
}