/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* L =(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next = head;
    if(!head)return NULL;
    struct ListNode* front = L;
    struct ListNode* rear = head;
    while(rear){
        if(front->val == rear->val){//删除操作
            front->next = rear->next;
            rear = rear -> next;
        }
        else{//两个指针同时移动
            rear = rear -> next;
            front = front ->next;
        }
    }
    return L->next;
}