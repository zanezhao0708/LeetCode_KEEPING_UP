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
int** levelOrderBottom(struct TreeNode* root,
                       int* returnSize,
                       int** returnColumnSizes) {

    int** ans = malloc(sizeof(int*) * 2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    *returnSize = 0;

    if (!root)
        return ans;

    struct TreeNode* queue[2000];
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {

        // 当前层节点个数
        int len = tail - head;

        ans[*returnSize] = malloc(sizeof(int) * len);

        // 只处理当前层的 len 个节点
        for (int i = 0; i < len; i++) {

            struct TreeNode* node = queue[head++];

            ans[*returnSize][i] = node->val;

            if (node->left)
                queue[tail++] = node->left;

            if (node->right)
                queue[tail++] = node->right;
        }

        (*returnColumnSizes)[*returnSize] = len;
        (*returnSize)++;
    }

    // 翻转各层
    int i = 0;
    int j = *returnSize - 1;

    while (i < j) {

        // 翻转每层数组的指针
        int* temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;

        // 同时翻转每层节点数
        int temp_num = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[j];
        (*returnColumnSizes)[j] = temp_num;

        i++;
        j--;
    }

    return ans;
}