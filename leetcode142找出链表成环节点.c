/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 bool NhasCycle(struct ListNode *head){
    struct ListNode *p=head;//ÂýÖ¸Õë 
    struct ListNode *q=head;//¿ìÖ¸Õë 
    while(q!=NULL){
    	for(int i=0;i<2;i++){
       	q=q->next;
       	if(q==NULL)break;
       	if(p==q)return false;
	   }
		p=p->next;        
	}
	return true; 
}
struct ListNode *detectCycle(struct ListNode *head) {
    if(NhasCycle(head))return NULL;
    struct ListNode *p=head;
    struct ListNode *q=head;
    struct ListNode *P=head;
    while(p!=NULL){
            for(int i=0;i<2;i++){
        	q=q->next;
        	if(p==q)break;}
		if(p==q)break;
    	p=p->next;
	}
	while(P!=p){
		do{q=q->next;
		if(P==q)return P;
		}while(p!=q);
		P=P->next;
	}
	return P;
}
