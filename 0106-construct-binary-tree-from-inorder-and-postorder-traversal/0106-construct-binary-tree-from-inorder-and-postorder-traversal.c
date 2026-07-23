/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(inorderSize == 0)return NULL;//递归出口
    
    //后序遍历的最后一个必然是根节点
    struct TreeNode* tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree->val = postorder[postorderSize-1];
    int id;
    for(id= 0;id<inorderSize;id++){//找到中序序列中相应的值所在下标id
        if(inorder[id] == postorder[postorderSize-1])break;
    }
    tree->left = buildTree(inorder,id,postorder,id);//id左侧全为当前根节点的左子树集合
    tree->right = buildTree(inorder + id + 1, inorderSize - id - 1, postorder + id, inorderSize - id - 1);
    return tree;

}