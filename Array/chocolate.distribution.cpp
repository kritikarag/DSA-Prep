long long findMinDiff(vector<long long> a, long long n, long long m){
   
    sort(a.begin(),a.end());
    long long req=INT_MAX,i,j;
    i=0,j=m-1;
    while(i<=j && j<n){
        req=min(req,a[j]-a[i]);
        i++;
        j++;
    }
    return req;
    }  
