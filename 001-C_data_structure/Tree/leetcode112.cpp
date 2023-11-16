//判断二叉树中是否存在一条从根节点到叶子节点的路径，使得路径上所有节点的值之和等于给定的sum
bool hasPathSum(struct TreeNode* root, int sum) {
    //首先判断当前节点是否为空，如果为空，则直接返回false。
    if (root == NULL) return false;
    //然后判断当前节点是否为叶子节点，即左右子节点都为空。如果是叶子节点，则判断当前节点的值是否等于sum，如果相等则返回true，否则返回false。
    if (root->left == 0 && root->right == NULL) return root->val == sum;
    //分别递归地判断左右子树中是否存在从根节点到叶子节点的路径，使得路径上所有节点的值之和等于sum减去当前节点的值
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
