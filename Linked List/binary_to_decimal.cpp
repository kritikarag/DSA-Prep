#include<bits/stdc++.h>
using namespace std;
//Approach 1
class ListNode{
    public:
    int val;
    ListNode *next,*head;
};

ListNode* reverse(ListNode* head){
        ListNode* prev=NULL,*curr=head,*nxt = NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        if(!head)return 0;
        if(!head->next)return head->val;
        
        ListNode* heads=reverse(head);
        int count=0,res=0;
        while(heads){
            if(heads->val==1){
                res+=pow(2,count);
                count++;
            }
            else{
                count++;
            }
            heads=heads->next;
        }
        return res;
    }

//Approach 2

int getDecimalValue(ListNode* head) {
        
        int res = 0;
        
        while(head)
        {
            res = res*2 + head->val;
            head = head->next;
        }
        
        return res;
    }
