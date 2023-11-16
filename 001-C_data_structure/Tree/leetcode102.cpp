int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}
//用递归的方式，让每层加一
void getCnt(struct TreeNode *root, int k, int *cnt) {
    if (root == NULL) return ;
    cnt[k] += 1;
    getCnt(root->left, k + 1, cnt);
    getCnt(root->right, k + 1, cnt);
    return ;
}

void getResult(struct TreeNode *root, int k, int *cnt, int **ret) {
    if (root == NULL) return ;
    ret[k][cnt[k]++] = root->val;
    getResult(root->left, k + 1, cnt, ret);
    getResult(root->right, k + 1, cnt, ret);
    return ;
}

/**层序遍历的方式，让这个树转化成一个二维数组**/
int** levelOrder(struct TreeNode* root, int* returnSize, int** columnSizes) {
    int depth = getDepth(root);                         //计算出二叉树的深度
    int *cnt = (int *)calloc(sizeof(int), depth);       //根据深度动态分配内存
    getCnt(root, 0, cnt);                               //getCnt函数递归地统计每一层的节点数量，并将结果存储在cnt数组中
    int **ret = (int **)malloc(sizeof(int *) * depth);  //申请分配一个二维数组
    for (int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;
    }
    getResult(root, 0, cnt, ret);	//将上面每层的cnt的内容存储到一个全新的二维数组
    *returnSize = depth;
    *columnSizes = cnt;
    return ret;
}

