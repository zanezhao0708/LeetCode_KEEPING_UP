/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc(  sizeof(int*)  *  2000);
    *returnColumnSizes = malloc(  sizeof(int) * 2000);
    *returnSize = 0;

    if(!root)return ans;//空树

    struct TreeNode* queue[2000];//数组模拟队列

    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while(front < rear){
        int len = rear - front;//当前层有多少个节点（实际是该层末尾下标减去上一层末尾下标得到的）
        
        ans[*returnSize] = malloc(  sizeof(int) * len);
        
        int start = front;
        front = rear;
        for(int i = start;i < front;i++){
            ans[*returnSize][i-start] = queue[i]->val;
            if(queue[i]->left)queue[rear++] = queue[i]->left;
            if(queue[i]->right)queue[rear++] = queue[i]->right;
        }
        (*returnColumnSizes)[*returnSize] = len;
        (*returnSize)++;
    }
    return ans;
}
