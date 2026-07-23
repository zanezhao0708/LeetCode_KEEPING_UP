/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head)return false;
    //利用快慢指针：快指针每次走两步，慢指针每次走一步，若有环最终必定相遇
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(true){
        if (fast == NULL || fast->next == NULL) 
        return false;//链表有尾，必然没有循环
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)return true;//找到循环点位
        
    }
}