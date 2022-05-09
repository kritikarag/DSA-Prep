Node* segregate(Node *head) {
        int zero=0,one=0,two=0;
        Node*curr = head;
        while(curr){
            if(curr->data==0)zero++;
            else if(curr->data==1)one++;
            else two++;
            curr=curr->next;
        }
        curr=head;
        while(zero--){
           curr->data=0;
           curr=curr->next;
        }
        while(one--){
            curr->data=1;
            curr=curr->next;
        }
        while(two--){
            curr->data=2;
            curr=curr->next;
        }
        
        return head;
        // Add code here
    }
