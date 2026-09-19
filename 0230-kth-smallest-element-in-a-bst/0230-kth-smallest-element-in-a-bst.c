/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ans = -1;

void dfs(struct TreeNode* root,int* count,int k){
    if(!root)return;
    dfs(root->left,count,k);
        
    (*count)++;
    if((*count) == k)ans = root->val;

    dfs(root->right,count,k);
}

int kthSmallest(struct TreeNode* root, int k) {
    ans;
    int count = 0;
    dfs(root,&count,k);
    return ans;
}