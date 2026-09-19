/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int* count,int* ans){
    if(!root)return;
    dfs(root->left,count,ans);
    ans[(*count)++] = root->val;
    dfs(root->right,count,ans);
}

int minDiffInBST(struct TreeNode* root) {
    int ans[100];
    int count = 0;
    dfs(root,&count,ans);
    int min_dis =INT_MAX;
    for(int i = 1;i < count;i++){
        if(abs(ans[i]-ans[i-1]) < min_dis)min_dis = abs(ans[i]-ans[i-1]);
    }
    return min_dis;
}