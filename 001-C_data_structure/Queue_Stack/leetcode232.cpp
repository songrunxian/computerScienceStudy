typedef struct {
    int *data;
    int top;
} MyStack;

MyStack* myStackCreate(int maxSize) {
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->data = (int *)malloc(sizeof(int) * maxSize);
    s->top = -1;
    return s;
}

/** Push element x to the back of queue. */
void myStackPush(MyStack* obj, int x) {
    obj->data[++(obj->top)] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myStackPop(MyStack* obj) {
    return obj->data[(obj->top)--];
}

/** Get the front element. */
int myStackTop(MyStack* obj) {
   return obj->data[obj->top]; 
}

/** Returns whether the queue is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}
/**
要用两个栈来模拟队列，可以按照以下步骤进行操作：

创建两个栈，分别称为stack1和stack2。
当要执行入队操作时，将元素压入stack1。
当要执行出队操作时，首先检查stack2是否为空，如果不为空，则直接从stack2弹出栈顶元素作为出队结果；如果stack2为空，则将stack1中的所有元素依次弹出并压入stack2，然后再从stack2弹出栈顶元素作为出队结果。
当要执行获取队首元素操作时，首先检查stack2是否为空，如果不为空，则直接返回stack2的栈顶元素作为队首元素；如果stack2为空，则将stack1中的所有元素依次弹出并压入stack2，然后返回stack2的栈顶元素作为队首元素。
通过交替使用两个栈，可以实现队列的入队、出队和获取队首元素操作。
 **/
typedef struct {
    MyStack *s1, *s2;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->s1 = myStackCreate(maxSize);
    q->s2 = myStackCreate(maxSize);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    myStackPush(obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (myStackEmpty(obj->s2)) {
        while (!myStackEmpty(obj->s1)) {
            myStackPush(obj->s2, myStackPop(obj->s1));
        }
    }
    return myStackPop(obj->s2);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (myStackEmpty(obj->s2)) {
        while (!myStackEmpty(obj->s1)) {
            myStackPush(obj->s2, myStackPop(obj->s1));
        }
    }
    return myStackTop(obj->s2);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return myStackEmpty(obj->s1) && myStackEmpty(obj->s2); 
}

void myQueueFree(MyQueue* obj) {
    myStackFree(obj->s1);
    myStackFree(obj->s2);
    free(obj);
    return ;
}





