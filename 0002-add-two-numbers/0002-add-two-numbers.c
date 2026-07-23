/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int flag = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = head;   //尾指针
    head->next = NULL;

    while (l1 || l2 || flag) {    
        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next = NULL;           //初始化 next
        
        int sum = flag;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        
        cur->val = sum % 10;
        flag = sum / 10;           
        
        tail->next = cur;           //链接到尾部
        tail = cur;                 //tail 后移
    }
    
    return head->next;
}