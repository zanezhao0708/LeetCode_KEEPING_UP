/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 1000);
    int** ans = malloc(sizeof(int*) *10000);
    if(!root)return ans;
    
    int rear = 0;
    int front = 0;
    struct Node *queue[10000];
    queue[rear++] = root;
    while(front < rear){
        int len = rear-front;
        ans[*returnSize] = malloc(sizeof(int) * len);
        for(int i = 0;i < len;i++){
            ans[*returnSize][i] = queue[front]->val;
            for(int j = 0;j<queue[front]->numChildren;j++){
                if(queue[front]->children[j])queue[rear++] = queue[front]->children[j];
            }
            front++;
        }
        (*returnColumnSizes)[(*returnSize)++] = len;
    }
    return ans;
}