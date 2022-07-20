ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         
        ListNode*temp=new ListNode(0);
        ListNode* head =temp;
        int carry=0,sum=0;
        while(l1&&l2){
            sum=(l1->val+l2->val+carry);
            temp->next=new ListNode(sum%10);
            carry=sum/10;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            sum=l1->val+carry;
            temp->next=new ListNode(sum%10);
            carry=sum/10;
            l1=l1->next;
            temp=temp->next;
        }
         while(l2){
            sum=l2->val+carry;
            temp->next=new ListNode(sum%10);
            carry=sum/10;
            l2=l2->next;
            temp=temp->next;
        }
        if(carry)temp->next=new ListNode(carry);
        
        return head->next;
    }
