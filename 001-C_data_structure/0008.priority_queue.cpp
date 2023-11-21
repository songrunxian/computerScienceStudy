#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

//优先队列和普通队列相比总是先出自己的最大最小值
typedef struct priority_queue {
    int *data;		//连续存储空间
    int cnt, size;	//cnt当前存储多少，size这个队列的大小是多大
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));	//堆的本质是一个完全二叉树,所以编号下表左2i，右一般是2i+1;为了方便锁定位置，我们一般从数组下标1开始，所以这里面是从下标1开始。这里开辟n + 1
    q->cnt = 0;
    q->size = n;
    return q;
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

//队列判空
int empty(priority_queue *q) {
    return q->cnt == 0;
}

//展示队列头
int top(priority_queue *q) {
    return q->data[1];
}

//入队
int push(priority_queue *q, int val) {
    //如果队空，或者队满。那么入队失败
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    //插入直接放在队尾。然后按照二叉树一样自下而上直接调整
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    //这里面的移位操作本质上就是除以2,这里的本质就是用数组去模拟树
    //调整就是放在队尾然后模拟树，一点一点从下向上调整
    while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    //队空或者队无就出队失败
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    //队尾放队头（本质上就是原队头出队了），然后自上而下的调整
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;	//这里有一个技巧，"+1" 即 | 1
        if (q->data[l] > q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

int main() {
    srand(time(0));
    #define max_op 20
    priority_queue *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("insert %d to queue\n", val);
    }
    for (int i = 0; i < max_op; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    clear(q);
    return 0;
}
