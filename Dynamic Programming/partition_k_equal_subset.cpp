int check(){

}

bool possible(int arr,int n,int k){
    if(k>n)return false;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%k!=0)return false;

    return check()
}