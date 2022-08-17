//Iterative Approach
ListNode* reverseList(ListNode* head) {
    ListNode* prev=NULL, *curr=head, *next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev = curr;
        curr=next;
    }
    return prev;
}  

//Recursive Approach
ListNode* reverseList(ListNode* head){
    if(head==NULL||head->next==NULL)
        return head;
    
    ListNode* start = reverseList(head->next);
    head->next->next=head;
    head->next=NULL;

    return start;
}
