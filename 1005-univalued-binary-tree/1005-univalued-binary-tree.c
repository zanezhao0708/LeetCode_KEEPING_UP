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
    bool L = dfs(root->left ,n);//左
    bool R = dfs(root->right,n);//右
    bool res =(root->val == n)&& L &&R;
    return res;

}

bool isUnivalTree(struct TreeNode* root) {
    int n = root->val;
    return dfs(root,n);
}
