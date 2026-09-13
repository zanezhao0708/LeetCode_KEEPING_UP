#include <stdlib.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int* largestValues(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    if (root == NULL) {
        return NULL;
    }

    int* ans = malloc(sizeof(int) * 10000);

    struct TreeNode* queue[10000];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        // 当前这一层的结束位置
        int len = rear;
        int maxNum = INT_MIN;

        while (front < len) {
            struct TreeNode* node = queue[front++];

            if (node->val > maxNum) {
                maxNum = node->val;
            }

            if (node->left) {
                queue[rear++] = node->left;
            }

            if (node->right) {
                queue[rear++] = node->right;
            }
        }

        ans[(*returnSize)++] = maxNum;
    }

    return ans;
}