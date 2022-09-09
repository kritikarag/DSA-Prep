bool partition(vector<int>&vec){
    int sum=0;
    for(int i=0;i<n;i++)sum+=vec[i];

    if(sum%2!=0)return false;

    int target = sum/2;
    vector<bool>prev(target+1,false);

    prev[0]=true;
    if(vec[0]<=target)prev[vec[0]]=true;

    for(int i=1;i<n;i++){
        vector<bool>curr(target+1,false);
        curr[0]=true;
        for(j=1;j<=target;j++){
            bool not_take = prev[j];
            bool take = false;
            if(vec[i]<=j){
                take = prev[j-vec[i]];
            }

            curr[j] = take||not_take;
        }
        prev = curr;
    }

    return prev[target];
}