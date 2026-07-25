/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->next = head;

    struct ListNode* cur = L;
    while(cur->next){
        struct ListNode* nxt = cur ->next;
        if(nxt -> val == val){//删除节点nxt
            cur->next = nxt->next;
            free(nxt);
        }
        else cur = nxt;


    }
    return L->next;
}