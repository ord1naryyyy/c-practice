#define maxlen 10000
typedef struct {
  	char bracket[maxlen];
	int top;
  }kstack;
  
void stack_push(kstack *q,char b){
	q->bracket[++q->top]=b;
}

char stack_pop(kstack *q){
	return q->bracket[q->top--];
}

char stack_peek(kstack* q){
	return q->bracket[q->top];
}

bool isValid(char* s) {
    kstack *p=malloc(sizeof(kstack));//栈 
    p->top=-1;
    int idx=0;
    int j=1;//判断是否符合要求的flag 
    while(s[idx]!='\0'){
    	if(p->top==-1&&(s[idx]==')'||s[idx]==']'||s[idx]=='}')) return false;
    	if(s[idx]=='('||s[idx]=='['||s[idx]=='{')stack_push(p,s[idx++]);
    	if(s[idx]==')'||s[idx]==']'||s[idx]=='}'){
    		char bkt=stack_peek(p);
    		if(s[idx]!=bkt+1&&s[idx]!=bkt+2){
    			j=0;//出现不符合情况即结束循环 
    			break;
			}
			else{p->top--;
			idx++;
			}
		}
	}
	if(p->top!=-1)j=0;
	if(j)return true;
	else return false;
}


