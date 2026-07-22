/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root,int n){
    if(!root)return 1 ;
    return (root->val == n)&&dfs(root->left,n) && dfs(root->right,n);

}

bool isUnivalTree(struct TreeNode* root) {
    int n = root->val;
    return dfs(root,n);
}
