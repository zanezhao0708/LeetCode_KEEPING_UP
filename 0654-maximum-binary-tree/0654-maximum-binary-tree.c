/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if(numsSize == 0)return NULL;//递归出口
    struct TreeNode* tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int max = 0;
    int max_id = 0;
    for(int i = 0;i < numsSize;i++){//寻找当前最大值
        if(nums[i]>max){
            max = nums[i];
            max_id = i;
        }
    }
    tree->val = nums[max_id];
    tree->left = constructMaximumBinaryTree(nums,max_id);
    tree->right = constructMaximumBinaryTree(nums+max_id+1,numsSize- max_id -1);
    return tree;
}