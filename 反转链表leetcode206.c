/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;   /* 已反转那段的头 */
    struct ListNode *cur  = head;   /* 当前要处理的节点 */

    while (cur != NULL) {
        struct ListNode *next = cur->next;  /* ① 先存后面，否则断链就找不回了 */
        cur->next = prev;                   /* ② 掉头 */
        prev = cur;                         /* ③ prev 前进 */
        cur  = next;                        /* ④ cur 前进 */
    }
    return prev;                    /* cur 走到 NULL 时，prev 就是新头 */
}

/*struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* copy=head;
    struct ListNode* p=head;
    int b=0;
   while(p->next!=NULL){
   	if(b==0){   
	p=p->next;
   	copy->next=NULL;
   	copy=p;
   	b=1;
	   }
	else{
		p=p->next;
		copy->next
	}
   }
	
	
}
