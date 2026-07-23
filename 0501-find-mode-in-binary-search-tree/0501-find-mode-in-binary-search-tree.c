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
int base = -999;
int count = 0;
int maxCount = 0;
int arrSize = 0;
int* arr = NULL;

void update(int x){
    if(x == base)++count;
    else{
        count = 1;
        base = x;
    }
    if(count == maxCount)arr[arrSize++] = base;
    if(count > maxCount){
        maxCount = count;
        arrSize = 0;
        arr[arrSize++] = base;
    }
}

void dfs(struct TreeNode* root){
    if(!root)return;
    dfs(root->left);
    update(root->val);
    dfs(root->right);
}

int* findMode(struct TreeNode* root,int *returnSize){
    base = count = maxCount = 0;
    arr = (int*)malloc(sizeof(int)*4001);    
    dfs(root);
    *returnSize = arrSize;
    return arr;
}