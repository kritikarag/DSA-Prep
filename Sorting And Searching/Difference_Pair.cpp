bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    for(int i=0;i<size;i++){
       int find=arr[i]+n;
       int start=i+1;
       int end=size-1;
       int mid=start+(end-start)/2;
       while(start<=end){
           if(arr[mid]==find)return true;
           else if(arr[mid]>find) end=mid-1;
           else start=mid+1;
           mid=start+(end-start)/2;
       }
   }
   return false;
}
