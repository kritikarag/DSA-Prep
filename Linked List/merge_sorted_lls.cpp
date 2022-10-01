  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


// Time Complexity -> O(N) Space Complexity -> O(N)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head=new ListNode(0);
    ListNode*temp=head;
    while(list1 && list2){
        if(list1->val<list2->val){
            temp->next = new ListNode(list1->val);
            list1=list1->next;
            temp=temp->next;
        }
        else{
            temp->next=new ListNode(list2->val);
            list2=list2->next;
            temp=temp->next;
        }
    }
    while(list1){
        temp->next = new ListNode(list1->val);
            list1=list1->next;
            temp=temp->next;
    }
    while(list2){
        temp->next=new ListNode(list2->val);
            list2=list2->next;
            temp=temp->next;
    }
    
    return head->next;
}

//Time Complexity-> O(N) Sopace Complexity-> O(1)

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if(!list1)return list2;
    if(!list2)return list1;
    if(list1->val>list2->val)swap(list1,list2);
    ListNode* res = list2;

    while (list1 && list2)
    {
         ListNode* temp = NULL;
        while(list2 && list1->val<=list2->val){
            temp=list1;
            list1=list1->next;
        }
        temp->next = list2;
        swap(list1,list2);
    }

    return res;
}
