#define MAXN 256

/* ---------- 队列：数组 + 头下标 + 计数，取模成环 ---------- */
typedef struct {
    int data[MAXN];
    int head;     /* 出队位置 */
    int count;    /* 元素个数 */
} Queue;

static void q_push(Queue *q, int x) {
    q->data[(q->head + q->count) % MAXN] = x;//head从来不减，是取余数组长度让结果保持在合法范围内，实现所谓“环形缓冲区” 
    q->count++;
}

static int q_pop(Queue *q) {
    int x = q->data[q->head];
    q->head = (q->head + 1) % MAXN;//相当于让front迁移一位（head+1），从队列里删掉了上一个front 
    q->count--;
    return x;
}

/* ---------- 栈：两个队列 + 角色指针 ---------- */
typedef struct {
    Queue a, b;
    Queue *cur;     /* 当前装数据的队列 ，并非实际存储的地方，只是指向实际位置的指针，方便后续交换位置*/
    Queue *tmp;     /* 搬运用队列 */
} MyStack;

MyStack* myStackCreate(void) {
    MyStack *s = malloc(sizeof(MyStack));
    s->a.head = s->a.count = 0;//初始化下标和元素个数 
    s->b.head = s->b.count = 0;
    s->cur = &s->a;//让两个指针分别指向实际队列 
    s->tmp = &s->b;
    return s;
}

void myStackPush(MyStack* obj, int x) {
    q_push(obj->cur, x);          /* 一律进 cur 的队尾 ，q没有实际意义，只是为了和myStackPush区别开*/
}

int myStackPop(MyStack* obj) {
    while (obj->cur->count > 1)   /* 搬走前 n-1 个 */
        q_push(obj->tmp, q_pop(obj->cur));

    int r = q_pop(obj->cur);      /* 剩下的最后那个 = 栈顶 */

    Queue *t = obj->cur;          /* 角色转换：O(1) 换指针 */
    obj->cur = obj->tmp;
    obj->tmp = t;
    return r;
}

int myStackTop(MyStack* obj) {
    while (obj->cur->count > 1)/*取出前n-1个*/ 
        q_push(obj->tmp, q_pop(obj->cur));

    int r = q_pop(obj->cur);/*接受取出的那一个TOP*/ 
    q_push(obj->tmp, r);          /* 看一眼再放回去 ，因为接只能从rear（head+count）接，取出来后不能再放到cur上
	                              然后再把tmp的放回来，那样会让top的那一个跑到front上，只有栈来回倒会倒序，队列这样干是不会的*/

    Queue *t = obj->cur;
    obj->cur = obj->tmp;
    obj->tmp = t;
    return r;
}

bool myStackEmpty(MyStack* obj) {
    return obj->cur->count == 0;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
