/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    int temp = node->val;
    if(!node->next)free(node);
    else{
        node ->val = node->next->val;
        node ->next->val = temp;
        node ->next = node->next->next;
    }
    
    return ;
}