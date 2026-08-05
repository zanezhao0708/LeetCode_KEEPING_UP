/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int flag = 0;
int *arr;
void dfs(struct TreeNode* root,int* arr){
    if(!root)return;
    dfs(root->left,arr);//左子树
    arr[flag++] = root->val;
    dfs(root->right,arr);//右子树
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    arr = (int*)malloc(sizeof(int)*100);
    flag = 0;
    dfs(root,arr);
    * returnSize = flag;
    return arr;
}