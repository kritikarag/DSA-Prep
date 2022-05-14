long long int minSum(int arr[], int n)
    {
        long long a=0,b=0;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            if(i%2==0)a = a*10+arr[i];
            else b=b*10+arr[i];
        }
        return a+b;
        // Your code goes here
    }
