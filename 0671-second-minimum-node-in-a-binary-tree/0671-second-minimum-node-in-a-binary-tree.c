/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int ans;
bool found;


void dfs(struct TreeNode* node, int minVal){
    if(node == NULL) return;
    if(node->val > minVal){
        if(!found || node->val < ans){
            ans = node->val;
            found = true;
        }
    }
    dfs(node->left, minVal);
    dfs(node->right, minVal);
}


int findSecondMinimumValue(struct TreeNode* root)
{
    found = false;
    dfs(root, root->val);
    return found ? ans : -1;
}