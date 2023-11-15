#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10000
/**在这个宏里面我让temp的类型和a一致**/
#define swap(a, b) { \
    __typeof(a) temp = a; \
    a = b, b = temp; \
}

typedef struct Node {
    char ch; 			//数据域
    double p;			//当前节点对应的概率值
    struct Node *next[2];	//左孩子，右孩子
} Node;

//相关字符，以及相关字符的编码
typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct HaffmanTree {
    Node *root;
    int n;		//判断haffuman树有多少种字符
    Code *codes;	//多少种编码
} HaffmanTree;

typedef struct Data {
    char ch;
    double p;
} Data;

Data arr[MAX_N + 5];

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = (obj ? obj->ch : 0);
    p->p  = (obj ? obj->p : 0);
    p->next[0] = p->next[1] = NULL;
    return p;
}

HaffmanTree *getNewTree(int n) {
    HaffmanTree *tree = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    tree->root = NULL;
    tree->n = n;
    return tree;
}

void insertOnce(Node **arr, int n) {	//n是插入排序范围最后一位的阈值
    for (int j = n; j >= 1; j--) {
        if (arr[j]->p > arr[j - 1]->p) {
            swap(arr[j], arr[j - 1]);
            continue;
        }
        break;
    }
    return ;
}



/**
root：哈夫曼树的根节点。
arr：存储每个叶子节点的编码的数组。
k：当前节点在 arr 数组中的下标。
l：当前节点的深度。
buff：存储编码的缓冲区。
函数的实现过程是通过递归遍历哈夫曼树来完成的。当遍历到叶子节点时，将该节点对应的字符和编码存储到 arr 数组中，并返回 1。当遍历到非叶子节点时，将该节点的编码存储到 buff 缓冲区中，并递归遍历左右孩子节点。遍历左孩子时，在 buff 缓冲区的末尾添加字符 '0'，遍历右孩子时，在 buff 缓冲区的末尾添加字符 '1'。递归返回时，将缓冲区的末尾字符删除，以便下一次遍历。

这样做的目的是为了构建每个叶子节点对应的编码。在哈夫曼树中，从根节点到每个叶子节点的路径上都对应着一个编码，左孩子对应 '0'，右孩子对应 '1'。通过递归遍历哈夫曼树，可以构建出每个叶子节点对应的编码，并将其存储到 arr 数组中。
 **/
int extractCodes(Node *root, Code *arr, int k, int l, char *buff) {
    buff[l] = 0;
    //寻找叶子节点
    if (root->next[0] == NULL && root->next[1] == NULL) {
        arr[k].ch = root->ch;
        arr[k].str = strdup(buff);
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    delta += extractCodes(root->next[0], arr, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extractCodes(root->next[1], arr, k + delta, l + 1, buff);
    return delta;
}

HaffmanTree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);
    //将 n 个 Node 数据逐个输入
    for (int i = 0; i < n; i++) {
        nodes[i] = getNewNode(arr + i);
    }
    //接下来进行n-1轮的合并,根据概率小的编码长，先对概率进行整体排序,所以我针对概率进行排序
    for (int i = 1; i < n; i++) {
	insertOnce(nodes, i);
    }
    //从后向前，按照概率大小进行节点合并,我将第i个和第i-1合并然后放在第i-1位   
    for (int i = n - 1; i >= 1; i--) {
        Node *p = getNewNode(NULL);
        p->next[0] = nodes[i - 1];
        p->next[1] = nodes[i];
        p->p = p->next[0]->p + p->next[1]->p;
	nodes[i - 1] = p;
        insertOnce(nodes, i - 1);
    }
    char *buff = (char *)malloc(sizeof(char) * n);
    HaffmanTree *tree = getNewTree(n);
    tree->root = nodes[0];
    extractCodes(tree->root, tree->codes, 0, 0, buff);
    free(nodes);
    free(buff);
    return tree;
}

int main() {
    int n;
    char str[10];
    scanf("%d", &n);
    //接下来，要逐个输入每个字符的数据域以及其对应的概率
    //由于我输入的是两个字段，所以我需要封装成结构体,这就是上面的Data
    for (int i = 0; i < n; i++) {
	scanf("%s%lf", str, &arr[i].p); //这里面使用%s，不用%c是担心突然出现无意识的输入换行空格等，所以干脆取字符串第一个就好
        arr[i].ch = str[0];
    }
    HaffmanTree *tree = build(arr, n); //在arr里面构建一个带有n个节点的哈夫曼树
    for (int i = 0; i < tree->n; i++) {
        printf("%c : %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
