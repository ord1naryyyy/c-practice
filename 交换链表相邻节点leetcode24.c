/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
	if(head==NULL||head->next==NULL)return head;
	struct ListNode* cp1=head;
    struct ListNode* cp2=head->next;
    cp1->next=cp2->next;
	cp2->next=cp1;
	head=cp2;
	if(cp1->next!=NULL&&cp1->next->next!=NULL){
	do{
	struct ListNode* cp3=cp1->next;
	struct ListNode* cp4=cp1->next->next;
	cp1->next=cp1->next->next;
	cp1=cp3;
	cp2=cp4;
	cp1->next=cp2->next;
	cp2->next=cp1;
    }while(cp1->next!=NULL&&cp1->next->next!=NULL);
	}
	return head;
}
