//root 定义为最近公共祖先
//点的值是否等于p或q的值，如果等于，则直接返回p或q作为最近公共祖先
//首先定义了一个内部函数__lowestCommonAncestor，用于查找最近公共祖先。该函数的参数包括当前节点root以及需要查找的两个节点p和q。
/*首先判断当前节点的值是否等于p或q的值，如果等于，则直接返回p或q作为最近公共祖先。
然后判断p和q是否分别位于当前节点的左右子树中，如果是，则当前节点即为最近公共祖先，返回当前节点。
如果p的值小于当前节点的值且q的值大于当前节点的值，说明p和q分别位于当前节点的左右子树中，返回当前节点作为最近公共祖先。
如果p的值大于当前节点的值，说明p和q都位于当前节点的右子树中，递归调用__lowestCommonAncestor函数在右子树中查找最近公共祖先。
如果以上条件都不满足，说明p和q都位于当前节点的左子树中，递归调用__lowestCommonAncestor函数在左子树中查找最近公共祖先。
最后，定义了一个外部函数lowestCommonAncestor，在该函数中进行一些预处理操作，如判断根节点是否为空，判断p和q是否相等等。然后调用__lowestCommonAncestor函数查找最近公共祖先并返回结果。*/

//注意这里是二叉检索树，数字大小是有定义的

struct TreeNode* __lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root->val == p->val) return p;
    if (root->val == q->val) return q;
    if (p->val < root->val && q->val > root->val) return root;
    if (p->val > root->val) return __lowestCommonAncestor(root->right, p, q);
    return __lowestCommonAncestor(root->left, p, q);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (p->val == q->val) return p;
    
    //确保p是小数，q是大数
    if (p->val > q->val) {
        struct TreeNode *temp = p;
        p = q;
        q = temp;
    }

    return __lowestCommonAncestor(root, p, q);
}
