/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head->next==NULL){
    	head=NULL;
	}else{
	
	struct ListNode* cur=head;
    int b1=1;//完成删除为0，未完成为1 

    while(b1){
    	struct ListNode* find=cur;
    	for(int i=0;i<n;i++){
		find=find->next;	
		}
		if(find==NULL){//判断是否删头指针 
			head=head->next;
			return head;
		}
		if(find->next==NULL){

			cur->next=cur->next->next;
			b1=0;
			
		}
		cur=cur->next;
	}
}
	return head;
}
