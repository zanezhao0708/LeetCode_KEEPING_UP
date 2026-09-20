bool dfs(struct TreeNode* root, long long* pre) {
    if (root == NULL) {
        return true;
    }
    if (!dfs(root->left, pre)) { // 左
        return false;
    }
    if (root->val <= *pre) { // 中
        return false;
    }
    *pre = root->val;
    return dfs(root->right, pre); // 右
}

bool isValidBST(struct TreeNode* root) {
    long long pre = LLONG_MIN;
    return dfs(root, &pre);
}
