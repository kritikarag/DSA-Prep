Node* divide(int N, Node *head){
        // code here
        Node* even=new Node(-1), *odd=new Node(-1);
        Node *ev=even,*od=odd;
        while(head!=NULL){
            if(head->data %2==0){
                even->next=head;
                even=even->next;
            }
            else{
                odd->next=head;
                odd=odd->next;
            }
            head=head->next;
        }
        odd->next=NULL;
        even->next=od->next;
        
        return ev->next;
    }
