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
