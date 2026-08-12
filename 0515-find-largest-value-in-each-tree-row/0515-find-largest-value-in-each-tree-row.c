/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ans = malloc(sizeof(int) *10000);
    if(!root)return ans;

    int rear = 0,front = 0;
    struct  TreeNode* queue[10000];
    queue[rear++] = root;
    
    while(front < rear){
        int max = INT_MIN;
        int len = rear - front;
        for(int i = 0;i<len;i++){
            if(queue[front]->val >max)max = queue[front]->val;
            if(queue[front]->left)queue[rear++] = queue[front]->left;
            if(queue[front]->right)queue[rear++] = queue[front]->right;
            front++;
        }
        ans[(*returnSize)++] = max;

    }
    return ans;
}