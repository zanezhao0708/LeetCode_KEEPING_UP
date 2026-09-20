/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* node, long long left, long long right) {
    if (node == NULL) {
        return true;
    }
    long long x = node->val;
    return left < x && x < right &&
           dfs(node->left, left, x) &&
           dfs(node->right, x, right);
}

bool isValidBST(struct TreeNode* root) {
    return dfs(root, LLONG_MIN, LLONG_MAX);
}
