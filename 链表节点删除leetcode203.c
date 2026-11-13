/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
 while(head!=NULL&&head->val==val){
 	struct ListNode* q=head;
 	head=head->next;
 	free(q);
 }
 if(head==NULL)return NULL;
  struct ListNode* p=head;
 while(p!=NULL&&p->next!=NULL){
 	if(p->next->val!=val)p=p->next;
 	else{
 		struct ListNode* q=p->next;
 		p->next=q->next;
 		free(q);
	 }
 }

return head;
}
