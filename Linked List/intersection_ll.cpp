struct ListNode{
    int val;
    ListNode*next;
};

ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
    ListNode* temp1=heada,*temp2=headb;
        while(temp1!=temp2){
            if(temp1==NULL)temp1=headb;
            else temp1=temp1->next;
            if(temp2==NULL)temp2=heada;
            else temp2=temp2->next;
        }
        return temp1;
}