/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* node, int x){
    if(!node)return 0;
    x = x*10 + node->val;
    if(node->left == NULL && node->right == NULL)return x;
    return dfs(node->left, x) + dfs(node->right, x);
}

int sumNumbers(struct TreeNode* root) {
   return dfs(root,0);
}