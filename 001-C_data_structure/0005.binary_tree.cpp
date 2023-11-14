#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;	//这棵树里面有几个节点
} Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}
Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

void clear_Node(Node *node) {
    if (node == NULL) return ;
    clear_Node(node->lchild);
    clear_Node(node->rchild);
    free(node);
    return ;
}
void clear_tree(Tree *tree) {
    if (tree == NULL) return ;
    clear_Node(tree->root);
    free(tree);
    return ;
}
/**这是一个二叉排序树的插入,所谓的二叉排序树就是插入如果小于根，插入左子树**/
/**所谓的二叉排序树就是插入如果大于根，插入右子树**/
/**所谓的二叉排序树就是插入如果等于根，返回根即可**/
/**如果是等于，那其实就涉及不到对树中的节点+1，所以这里面设计了一个标记位flag or *ret**/
Node *insertNode(Node *root, int val, int *ret) {
    if (root == NULL) {
        *ret = 1;
        return getNewNode(val);
    }
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insertNode(root->lchild, val, ret);
    else root->rchild = insertNode(root->rchild, val, ret);
    return root;
}
void insert(Tree *tree, int val) {
    int flag = 0;	
    tree->root = insertNode(tree->root, val, &flag);
    tree->n += flag;
    return ;
}
/**二叉树以广义表形式输出**/
void outputNode(Node *root) {
    if (root == NULL) return ;
    printf("%d", root->data);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return ;
}

void output(Tree *tree) {
    printf("tree(%d) : ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return ;
}
/**前中后三种遍历**/
void pre_orderNode(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->data);
    pre_orderNode(root->lchild);
    pre_orderNode(root->rchild);
    return ;
}

void pre_order(Tree *tree) {
    printf("pre_order : ");
    pre_orderNode(tree->root);
    printf("\n");
    return ;
}

void in_orderNode(Node *root) {
    if (root == NULL) return ;
    in_orderNode(root->lchild);
    printf("%d ", root->data);
    in_orderNode(root->rchild);
    return ;
}

void in_order(Tree *tree) {
    printf("in_order : ");
    in_orderNode(tree->root);
    printf("\n");
    return ;
}

void post_orderNode(Node *root) {
    if (root == NULL) return ;
    post_orderNode(root->lchild);
    post_orderNode(root->rchild);
    printf("%d ", root->data);
    return ;
}

void post_order(Tree *tree) {
    printf("post_order : ");
    post_orderNode(tree->root);
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 10
    Tree *tree = getNewTree();
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_tree(tree);
    return 0;
}
