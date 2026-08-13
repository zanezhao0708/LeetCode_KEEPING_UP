/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int widthOfBinaryTree(struct TreeNode* root) {
    int front = 0;
    int rear = 0;
    struct TreeNode* queue[3000];
    long long index[3000];
    queue[rear] = root;
    index[rear++] = 0;
    int max = 1;

    while (front < rear) {
        int len = rear - front;
        long long base = index[front];

        // 当前层宽度
        long long width = index[rear - 1] - base + 1;
        if (width > max)
            max = width;

        // 处理当前层的所有节点
        for (int i = 0; i < len; i++) {
            long long cur = index[front] - base;

            if (queue[front]->left) {
                queue[rear] = queue[front]->left;
                index[rear] = 2 * cur + 1;
                rear++;
            }
            if (queue[front]->right) {
                queue[rear] = queue[front]->right;
                index[rear] = 2 * cur + 2;
                rear++;
            }
            front++;
        }
    }

    return max;
}