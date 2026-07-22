/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root,int n){
    if(!root)return 1 ;//如果树空表示该路径成功
    return (root->val == n)&&dfs(root->left,n) && dfs(root->right,n);//所有路径均成功则完成

}

bool isUnivalTree(struct TreeNode* root) {
    int n = root->val;
    return dfs(root,n);
}
