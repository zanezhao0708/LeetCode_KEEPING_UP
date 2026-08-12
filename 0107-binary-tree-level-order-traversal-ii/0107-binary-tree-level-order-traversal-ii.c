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
int** levelOrderBottom(struct TreeNode* root,int* returnSize,int** returnColumnSizes) {
    int** ans = malloc( sizeof(int*) * 2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    *returnSize = 0;

    if(!root)return ans;

    int front = 0,rear = 0;
    struct TreeNode* queue[2000];
    queue[rear++] = root;

    while(front<rear){
        int start = front;
        int len = rear - front;

        ans[*returnSize] = malloc( sizeof(int) * len);
        front = rear;
        for(int i = start;i < front;i++){
            ans[*returnSize][i-start] = queue[i]->val;
            if(queue[i]->left)queue[rear++] = queue[i]->left;
            if(queue[i]->right)queue[rear++] = queue[i]->right;
        }

        (*returnColumnSizes)[(*returnSize)++] = len;
    }
    int i = 0;
    int j = *returnSize -1;
    while(i<j){
        int* temp = ans[i];
        ans[i] = ans[j];
        ans[j] =  temp;

        int tempnum = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[j];
        (*returnColumnSizes)[j] = tempnum;

        i++;
        j--;

    }


    return ans;
}