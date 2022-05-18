long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long first=0,second=0;
    long long mod= 1000000007;
    
    while(l1){
        first*=10;
        first=first%mod + l1->data;
        l1=l1->next;
    }
    
    while(l2){
        second*=10;
        second=second%mod + l2->data;
        l2=l2->next;
    }
    
    return (first%mod*second%mod); 
  //Your code here
}
