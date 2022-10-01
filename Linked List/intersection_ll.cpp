// https://leetcode.com/problems/intersection-of-two-linked-lists/

struct ListNode{
    int val;
    ListNode*next;
};

// Approach 1
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

//Approach 2 Space Complexity Optimized

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp1 = headA, *temp2 = headB;
    int len1=0,len2=0;
    while (temp1)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        len2++;
        temp2 = temp2->next;
    }
    if (len1 > len2)
    {
        int n = len1 - len2;
        while (n--)
        {
            headA = headA->next;
        }
    }
    if (len1 < len2)
    {
        int n = len2 - len1;
        while (n--)
        {
            headB = headB->next;
        }
    }

    while(headA!=headB){
        headA=headA->next;
        headB=headB->next;
    }
    return headA;
}

//Approach 3

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp1 = headA, *temp2 = headB;
    map<ListNode*,int>mp;
    while (temp1)
    {
        mp[temp]++;
        temp1 = temp1->next;
    }

    while(temp2){
        if(mp[temp2]>0)break;
        temp2 = temp2->next;
    }
    
    return temp2;
}