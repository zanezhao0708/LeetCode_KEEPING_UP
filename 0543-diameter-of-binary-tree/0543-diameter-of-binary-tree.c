/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max_val = 0;
int dfs(struct TreeNode* root){
    if(!root)return 0;
    int L = dfs(root->left);
    int R = dfs(root->right);
    if(L+R+1 > max_val) max_val = L+R;
    return fmax(L,R)+1;
}


int diameterOfBinaryTree(struct TreeNode* root) {
    max_val = 0; 
    int i = dfs(root);   
    return max_val;
}