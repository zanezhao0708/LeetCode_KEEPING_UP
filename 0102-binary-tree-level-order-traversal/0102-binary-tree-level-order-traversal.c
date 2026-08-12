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
        (*returnColumnSizes)[(*returnSize)++] = len;
    }
    return ans;

}


// int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
//     int** ans = (int**)malloc(sizeof(int*) * 2000);//开辟二维数组
//     *returnColumnSizes = malloc(sizeof(int) * 2000);// *returnColumnSizes数组记录每一层节点的个数
//     *returnSize = 0;

//     if(root == NULL) return ans;//若树为空，直接返回ans
    
//     struct TreeNode* queue[2000];
//     int head = 0, tail = 0;
//     queue[tail++] = root;
//     // 结束条件为队列为空，即tail==head
//     while(head != tail){
        
//         int len = tail - head;
//         ans[*returnSize] = malloc(sizeof(int) * len); // 开辟当前层的一维数组空间
        
//         int start = head;
//         head = tail;// start被赋值后变为当前层的头部，head被赋值后变为当前层的尾部
        
//         for(int i = start; i < head; i++){// 逐个访问当前层的节点值
//             ans[*returnSize][i - start] = queue[i]->val;//i和start都是在原树结构中的整体队列
//             //利用i-start相对位置构造第二维
//             // 访问完一个节点后，将此节点的左右孩子入队
//             if(queue[i]->left) queue[tail++] = queue[i]->left;
//             if(queue[i]->right) queue[tail++] = queue[i]->right;
//         }
//         // *returnColumnSizes赋值，并将层数加1
//         (*returnColumnSizes)[(*returnSize)++] = len;
//     }
//     return ans;

// }