// https://leetcode.com/problems/find-subarray-with-bitwise-and-closest-to-k/

// The main idea that we are using here is that AND operation reduces the value always
int n;
vector<vector<int>>dp;
vector<int>seg;
void build(int index, int low, int high, vector<int>&arr){
    if(low==high){
        seg[index] = arr[low];
        return;
    }
    int mid = (high+low)/2;

    build(2*index+1,low,mid,arr);
    build(2*index+2,mid+1,high,arr);

    seg[index] = seg[2*index+1]&seg[2*index+2];
}

int query(int index, int low, int high, int l , int r){
    if(r < low || high < l)return INT_MAX;

    if(l<=low && r>=high){
        return seg[index];
    }

    int mid = (low+high)/2;
    int left = query(2*index+1,low,mid,l,r);
    int right = query(2*index+2,mid+1,high,l,r);

    return left&right;
}
int rangequery(int left, int right){
    return query(0,0,n-1,left,right);
}
int minimumDifference(vector<int>& nums, int k) {
    n = nums.size();
    seg.resize(4*n,0);
    int ans = INT_MAX;
    build(0,0,n-1,nums);
    for(int i=0;i<n;i++){
        int left =i,right =n-1;
        while(left+1<right){
            int mid = (left+right)/2;
            int curr = rangequery(i,mid);
            if(curr>=k){
                left = mid;
            }
            else{
                right = mid;
            } 
        } 
        ans = min(ans,abs(rangequery(i,left)-k));
        ans = min(ans,abs(rangequery(i,right)-k));
    }
    return ans;
}
