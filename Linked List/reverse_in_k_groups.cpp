struct ListNode{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next)
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL||k==1)return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *curr = dummy, *fwd, *prev= dummy;
    int count = 0;
    while(curr->next){
        curr = curr->next;
        count++;
    }

    while(count>=k){
        curr = prev->next;
        for (int i = 1; i < k; i++)
        {
            fwd = curr->next;
            curr->next = fwd->next;
            fwd->next = prev->next;
            prev->next = fwd;
        }
        prev = curr;
        count-=k;
    }

    return dummy->next;
}