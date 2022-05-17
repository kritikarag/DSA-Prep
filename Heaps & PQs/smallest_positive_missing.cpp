int missingNumber(int arr[], int n) 
    { 
        int res[n+1]={0};
        for(int i=0;i<n;i++){
            if(arr[i]>0 && arr[i]<=n){
                res[arr[i]]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(res[i]==0)return i;
        }
        return n+1; 
    }
