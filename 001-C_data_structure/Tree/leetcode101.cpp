/*方法1，中序遍历然后字符串转置*/
/*方法2，改写leetcode100,但是注意这里面isSameTree的最后一行*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val - q->val) return false;
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isSameTree(root->left, root->right);
}
