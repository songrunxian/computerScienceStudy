//求树的深度
int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int d1 = getDepth(root->left);
    int d2 = getDepth(root->right);
    return fmax(d1, d2) + 1;
}

//将每层的节点保存在一个数组内
void getSize(struct TreeNode *root, int k, int *size) {
    if (root == NULL) return ;
    size[k] += 1;
    getSize(root->left, k - 1, size);
    getSize(root->right, k - 1, size);
    return ;
}

//将每层的节点保存在一个二维数组内部
void getData(struct TreeNode *root, int **ret, int *size, int k) {
    if (root == NULL) return ;
    ret[k][size[k]++] = root->val;
    getData(root->left, ret, size, k - 1);
    getData(root->right, ret, size, k - 1);
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) return NULL;
    int n = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * n);
    int *size = (int *)calloc(sizeof(int), n);
    getSize(root, n - 1, size);
    for (int i = 0; i < n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * size[i]);
        size[i] = 0; //将size[i]置为0，是因为在之后的遍历过程中，每遍历到一个节点，都会将该节点的值存储到ret[i][size[i]]中，并将size[i]加1，表示该层节点数加1。因此，在这里将size[i]置为0，是为了在之后的遍历过程中正确地记录每层节点数
    }
    getData(root, ret, size, n - 1);
    *returnSize = n;
    *columnSizes = size;
    return ret;
}
