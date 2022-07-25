ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        ListNode* curr=prev->next,*fwd;
        for(int i=0;i<right-left;i++){
            fwd=curr->next;
            curr->next=fwd->next;
            fwd->next=prev->next;
            prev->next=fwd;
        }
        return dummy->next;
    }
