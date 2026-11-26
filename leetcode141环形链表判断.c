/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p=head;//ÂıÖ¸Õë 
    struct ListNode *q=head;//¿ìÖ¸Õë 
    while(q!=NULL){
    	for(int i=0;i<2;i++){
       	q=q->next;
       	if(q==NULL)break;
       	if(p==q)return true;
	   }
		p=p->next;        
	}
	return false; 
}
