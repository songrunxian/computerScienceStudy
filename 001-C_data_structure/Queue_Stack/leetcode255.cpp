typedef struct {
    int *data;
    int head, tail;
    int size, cnt;
} MyQueue;

MyQueue* myQueueCreate(int size) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->size = size;
    q->cnt = 0;
    q->head = q->tail = 0;
    return q;
}

/** Push element x onto queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj == NULL) return ;
    if (obj->cnt == obj->size) return ;
    obj->data[obj->tail++] = x;
    if (obj->tail == obj->size) obj->tail -= obj->size;
    obj->cnt += 1;
    return ;
}

/** Removes the element on top of the stack and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (obj == NULL) return 0;
    if (obj->cnt == 0) return 0;
    obj->head += 1;
    if (obj->head == obj->size) obj->head -= obj->size;
    obj->cnt -= 1;
    return 1;
}

/** Get the top element. */
int myQueueFront(MyQueue* obj) {
    return obj->data[obj->head];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->cnt == 0;
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

/**
 *
创建两个队列，分别称为queue1和queue2。
当要执行push操作时，将元素添加到非空的队列中（如果两个队列都为空，可以选择任意一个队列）。
当要执行pop操作时，将非空队列中的元素依次出队并入队到另一个空队列中，直到剩下最后一个元素。
将剩下的最后一个元素出队，即为pop操作的结果。
 *
 **/
typedef struct {
    MyQueue *q1, *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->q1 = myQueueCreate(100);
    s->q2 = myQueueCreate(100);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (!myQueueEmpty(obj->q1)) {
        myQueuePush(obj->q1, x);
    } else {
        myQueuePush(obj->q2, x);
    }
    return ;
}

/** Removes the element on top of the stack and returns that element. */
/** 
这段代码实现了一个栈（stack）的pop操作，即弹出栈顶元素。这个栈是由两个队列（queue）实现的，分别为q1和q2。

在pop操作中，首先判断q1和q2中哪个队列不为空，并将其赋值给变量p。同时，将另一个队列赋值给变量q。这是因为在pop操作中，需要将队列中的元素依次移动到另一个队列中，以保证栈顶元素在队列的末尾。

然后，从队列p中取出队首元素，并将其弹出。接着，将队列p中的所有元素依次移动到队列q中。这里需要注意的是，在移动元素时，需要先将元素存储到变量element中，以便将其作为下一个元素的前驱节点。

最后，将变量element作为结果返回，即为栈顶元素。
 **/
int myStackPop(MyStack* obj) {
    MyQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element = myQueueFront(p);
    myQueuePop(p);
    while (!myQueueEmpty(p)) {
        myQueuePush(q, element);
        element = myQueueFront(p);
        myQueuePop(p);
    }
    return element;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    MyQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element;
    while (!myQueueEmpty(p)) {
        element = myQueueFront(p);
        myQueuePop(p);
        myQueuePush(q, element);
    }
    return element;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return myQueueEmpty(obj->q1) && myQueueEmpty(obj->q2);
}

void myStackFree(MyStack* obj) {
    if (obj == NULL) return ;
    myQueueFree(obj->q1);
    myQueueFree(obj->q2);
    free(obj);
    return ;
}

