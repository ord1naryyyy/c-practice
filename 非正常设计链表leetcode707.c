#include <stdlib.h>
typedef struct DLNode {
	int val;
	struct DLNode *prev,*next;
}DLNode;


typedef struct {
    DLNode *head,*tail;
    int size;
}MyDLinkedList;

void myDLinkedListAddAtIndex(MyDLinkedList* obj, int index, int val);


MyDLinkedList* myDLinkedListCreate() {//创建链表头尾节点 
MyDLinkedList *obj=malloc(sizeof(MyDLinkedList));
obj->head=malloc(sizeof(DLNode));
obj->tail=malloc(sizeof(DLNode));
obj->head->prev=NULL;
obj->head->next=obj->tail;
obj->tail->prev=obj->head;
obj->tail->next=NULL;
obj->size=0;
return obj;
   }


int myDLinkedListGet(MyDLinkedList* obj, int index) {//获取某节点下标 
    if(index<0||index>=obj->size)return -1;
	DLNode *found;
	if(index<obj->size/2){
		found=obj->head->next;
		for(int i=0;i<index;i++)found=found->next;
	}
	else {
		found=obj->tail;
		for(int i=index;i<obj->size;i++)found=found->prev;
	}
	return found->val;
}

void myDLinkedListAddAtHead(MyDLinkedList* obj, int val) {//头部增加节点 
   myDLinkedListAddAtIndex(obj, 0, val); 
}

void myDLinkedListAddAtTail(MyDLinkedList* obj, int val) {//尾部增加节点 
    myDLinkedListAddAtIndex(obj, obj->size, val);
}

void myDLinkedListAddAtIndex(MyDLinkedList* obj, int index, int val) {//节点插入 
   if(index<0||index>obj->size)return;
   DLNode *cur;
   if(index<obj->size/2){
   	cur=obj->head->next;
   	for(int i=0;i<index;i++)cur=cur->next;
   }
   else {
   	cur=obj->tail;
   	for(int i=index;i<obj->size;i++)cur=cur->prev;
   }//cur取插入位置后一个节点 
   DLNode *node=malloc(sizeof(DLNode));
   node->val=val;
   node->prev=cur->prev;
   node->next=cur;//把新插入节点连进链表 
   cur->prev->next=node;
   cur->prev=node;
   obj->size++;
}

void myDLinkedListDeleteAtIndex(MyDLinkedList* obj, int index) {//链表节点删除 
    if(index<0||index>=obj->size)return;
    DLNode *delet;
    if(index<obj->size/2){
    	delet=obj->head->next;
    	for(int i=0;i<index;i++)delet=delet->next;
	}
	else {
		delet=obj->tail;
		for(int i=index;i<obj->size;i++)delet=delet->prev;
	}
	delet->prev->next=delet->next;
	delet->next->prev=delet->prev;
	free(delet);
	obj->size--;
}

void myDLinkedListFree(MyDLinkedList* obj) {
    DLNode *cur=obj->head;
    while(cur!=NULL){
    	DLNode *next=cur->next;
    	free(cur);
    	cur=next;
	}
	free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
