/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *cur1 = headA;
    struct ListNode *cur2 = headB;
    int count = 0;
    int flag = -1;
    while(cur1->next !=NULL && cur2->next){
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    while(cur2->next != NULL){
        flag = 1;
        cur2 = cur2->next;
        count++;
    }
    while(cur1 ->next != NULL){
        flag = 0;
        cur1 = cur1->next;
        count++;
    }
    cur1 = headA;
    cur2 = headB;
    while(count--){
        if(flag)cur2 = cur2->next;
        else cur1 = cur1->next; }

    while(cur1!=cur2){
        if(cur1 == NULL || cur2 == NULL) return NULL;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;

}