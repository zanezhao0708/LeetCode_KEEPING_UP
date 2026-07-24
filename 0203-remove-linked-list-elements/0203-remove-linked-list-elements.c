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

    struct ListNode* front = L;
    struct ListNode* rear = head;

    while(rear){
        if(rear->val == val){
            front->next = rear->next;
            rear = rear -> next;
            //注意此时front指针不用移动
            //因为假设有连续要删除的变量，就会导致有应当删除节点的残留
        }
        else{
            front = front -> next;
            rear = rear -> next; 
        }
    } 
    return L->next;
}