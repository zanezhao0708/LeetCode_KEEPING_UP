/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize == 0)return NULL;//递归出口
    struct TreeNode* tree = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    tree->val = preorder[0];//前序序列的第一个元素必然为根节点的值
    int id;
    for(id = 0;id < inorderSize;id++){
        if(inorder[id] == preorder[0])break;
    }
    tree->left = buildTree(preorder+1,id,inorder,id);//注意前面区间长度是id
    tree->right = buildTree(preorder+ id +1,inorderSize- id -1,inorder+ id + 1,inorderSize-id-1);
    return tree;
}