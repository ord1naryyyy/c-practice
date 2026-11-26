/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  if(list1==NULL&&list2==NULL)return NULL;
  if(list1==NULL&&list2!=NULL)return list2;
  if(list2==NULL&&list1!=NULL)return list1;
  struct ListNode* head;
  struct ListNode* temp1=NULL;
  struct ListNode* temp2=NULL;
  if((list1->val)<(list2->val)){
  	head=list1;
  	if(head->next==NULL){
  		head->next=list2;
	    return head;
	  }
	else list1=list1->next;
}
  else{head=list2;
  if(head->next==NULL){
  	head->next=list1;
  	return head;
  }
  list2=list2->next;
}
   struct ListNode* p=head;
 while(1){
 	if(list1->next!=NULL)temp1=list1->next;
 	if(list2->next!=NULL)temp2=list2->next;
 	if(list1->val>list2->val){
 		p->next=list2;
 		p=p->next;
 		if(list2->next!=NULL)list2=temp2;
 		else{p->next=list1;
 			return head;
		 }
  } else{
  	    p->next=list1;
  	    p=p->next;
  	    if(list1->next!=NULL)list1=temp1;
  	    else{p->next=list2;
  	    return head;
		  }
        }
 }
 return head;
}
