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
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *ans = malloc( sizeof(int) * 2000);
    if(!root)return ans;

    int rear = 0,front = 0;
    struct TreeNode* queue[1000000];

    queue[rear++] = root;
    while(front < rear){
        int len = rear - front;
        int last = rear - 1;
        for(int i = 0;i < len;i++){
            if(i == len-1)ans[(*returnSize)++] = queue[front]->val;//注意入队都是要用“全局”的头
            if(queue[front]->left)queue[rear++] = queue[front]->left;
            if(queue[front]->right)queue[rear++] = queue[front]->right;
            front++;
        }
    }
    return ans;
}