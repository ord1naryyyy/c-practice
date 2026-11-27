
typedef struct {
    int in[128];
    int out[128];
    int inTop;      
    int outTop;
} MyQueue;

MyQueue* myQueueCreate(void) {
    MyQueue *q = malloc(sizeof(MyQueue));
    q->inTop = -1;
    q->outTop = -1;
    return q;                     
}

void myQueuePush(MyQueue* obj, int x) {
    obj->in[++obj->inTop] = x;      /* 输入的一律压进 in */
}

/* out 空时，把 in 整体倒过来；倒完 out 顶就是队头 */
static void shift(MyQueue *obj) {
    if (obj->outTop != -1) return;  /* 某一次调用shift之后out里存的元素一定比in里面的老，先进先出，
	                                out里的元素一定先出，等出完了，再从in里新push的元素倒过来*/ 
    while (obj->inTop != -1)        /*倒*/ 
        obj->out[++obj->outTop] = obj->in[obj->inTop--];
}

int myQueuePop(MyQueue* obj) {
    shift(obj);/*判断out里还有没有元素*/ 
    return obj->out[obj->outTop--]; /* 实际上return的是out里的元素*/
}

int myQueuePeek(MyQueue* obj) {
    shift(obj);/*判断out里还有没有元素*/ 
    return obj->out[obj->outTop];  
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->inTop == -1 && obj->outTop == -1;   /* 两个都空才算空 */
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/*  ********错的离谱*********** 
typedef struct {
    int data[128];
    int trans[128];
    int topd;
    int topt;
} MyQueue;//stack


MyQueue* myQueueCreate() {
    MyQueue *PtrS=malloc(sizeof(MyQueue));
    PtrS->topt=PtrS->topd=-1;
}

void myQueuePush(MyQueue* obj, int x) {
    PtrS->data[++(PtrS->topd)]=x;
}

int myQueuePop(MyQueue* obj) {
   //if(myQueueEmpty(PtrS))  这道题里所有操作都有效，不用判断 
   while(myQueueEmpty(PtrS)){
   	PtrS->trans[++(PtrS->topt)]=PtrS->data[PtrS->topd--];
   }
   int temp=PtrS->trans[(PtrS->topt)--];
   while((PtrS->topt)!=-1){
      PtrS->data[++(PtrS->topd)]=PtrS->trans[(PtrS->topt)--];
   }
   return temp; 
   }


int myQueuePeek(MyQueue* obj) {
       while(myQueueEmpty(PtrS)){
   	PtrS->trans[++(PtrS->topt)]=PtrS->data[PtrS->topd--];
   }
   int temp=PtrS->trans[(PtrS->topt)];
   while((PtrS->topt)!=-1){
      PtrS->data[++(PtrS->topd)]=PtrS->trans[(PtrS->topt)--];
   }
   return temp; 
}

bool myQueueEmpty(MyQueue* obj) {//不空为真 
    if(PtrS->topd==-1)return false;
    else return true;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
*/
/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
