/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root){
    if(!root)return 0;
    if(root->left == NULL && root->right == NULL)return 1;//判定叶子结点，叶子结点高度记为1
    
    int L;
    if(root->left)L =  dfs(root->left);//如果有左子树，记录左子树最小深度
    int R ;
    if(root->right)R = dfs(root->right);//同理记录右子树最小深度
    return fmin(L,R)+1;
}


int minDepth(struct TreeNode* root) {
    return dfs(root);
    
}