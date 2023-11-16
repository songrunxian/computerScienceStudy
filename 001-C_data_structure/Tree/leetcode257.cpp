#include <math.h>

int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}


/*
首先判断当前节点是否为空，如果为空则返回0。
使用sprintf函数将当前节点的值转换为字符串，并将其追加到buff数组中。
如果当前节点是叶子节点，即左右子节点都为空，则将buff数组中的路径字符串存储到ret数组中，并返回1。
如果当前节点不是叶子节点，则在buff数组中追加"->"字符串，并递归调用getResult函数遍历左右子树，将返回的路径数量累加到cnt变量中。
最后返回cnt变量，表示从当前节点到叶子节点的路径数量。
 */
int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if (root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buff);
        return 1;
    }
    len += sprintf(buff + len, "->");
    int cnt = getResult(root->left, len, k, ret, buff);
    cnt += getResult(root->right, len, k + cnt, ret, buff);
    return cnt;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getPathCnt(root);	//getpathcount()
    char **ret = (char **)malloc(sizeof(char *) * pathCnt); //存储路径结果
    int max_len = 10000;
    char *buff = (char *)malloc(sizeof(char) * max_len); //存储路径字符串
    getResult(root, 0, 0, ret, buff); //调用getResult函数，通过递归的方式遍历二叉树，将每条路径存储在ret数组中
    free(buff);
    *returnSize = pathCnt;
    return ret; //返回ret数组，即包含所有路径的二维字符数组
}
