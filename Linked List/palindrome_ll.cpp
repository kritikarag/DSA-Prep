ListNode* reverse(ListNode*head){
    ListNode* prev=NULL, *curr= head, *next = NULL;
    while(curr){
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;  
    }
    return prev;
}
    
bool isPalindrome(ListNode* head) {
    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*x=head;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;;
        
    }
    ListNode*heads=reverse(slow);
    while(head !=NULL and heads!=NULL){
        if(head->val!=heads->val){
            break;
        }
        head=head->next;
        heads=heads->next;
        
    }
    
    if(head==NULL || heads==NULL){
        return true;
    }
    return false;
}
