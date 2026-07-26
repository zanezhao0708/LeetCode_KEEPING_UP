/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    int sum = 0;
    struct ListNode* L = malloc(sizeof(struct ListNode));

    struct ListNode* front = L;//指向上一个0节点
    struct ListNode* rear = head->next;
    while(rear){
        if(rear->val == 0){//当前段已经结束了，收集
            front->next =rear;
            rear->val = sum;
            front = rear;
            sum = 0;
            rear = rear->next;
        }
        else{
            sum += rear->val;
            rear = rear->next;
        }
    }
    return L->next;
}   