/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* ans = NULL;

void dfs(struct TreeNode* root, int num){
    if(!root)return;
    dfs(root->left,num);
    if(root->val == num)ans = root;
    dfs(root->right,num);

}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    ans = NULL;
    dfs(root,val);
    return ans;
}