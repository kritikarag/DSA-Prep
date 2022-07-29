ListNode *removeduplicates(ListNode* head){
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;

    ListNode* dummy = new ListNode(0,head);
    ListNode* temp=head,*prev = dummy;

    while(temp){
        if(temp->next!=NULL && temp->val ==temp->next->val){
            while(temp!=NULL && temp->next->val==temp->val){
                temp=temp->next;
            }
            prev->next=temp->next;
        }
        else{
            prev=prev->next;
        }
        temp=temp->next;
    }

    return dummy->next;
}