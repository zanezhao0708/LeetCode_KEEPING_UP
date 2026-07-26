/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode** ans = ( struct ListNode**)malloc(sizeof(struct ListNode*)*k);
    int length=0;
    struct ListNode* cur=head;//计算长度
    while(cur!=NULL)
    {
        length++;
        cur=cur->next;
    }
    cur = head;
    int mod=length%k;//多出来的
    int size=length/k;
    for(int i=0;i<k;i++)
    {
        ans[i]=cur;  //如果i<k但是cur==NULL  
        //那么证明是特殊情况(length<k) 只将cur(即NULL)赋给数组元素 后面的都不执行
        if(cur!=NULL)
        {        
            int curSize=size+(mod-- >0? 1:0);            //亮点
            for(int j=0; j<curSize-1; j++) cur=cur->next;   //分割链表
            struct ListNode* next=cur->next;
            cur->next=NULL;
            cur=next;
        }
    }
    *returnSize = k;
    return ans;
}