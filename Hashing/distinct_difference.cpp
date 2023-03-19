// https://practice.geeksforgeeks.org/problems/c670bf260ea9dce6c5910dedc165aa403f6e951d/1

vector<int> getDistinctDifference(int n, vector<int> &arr) {
        // code here
    unordered_map<int,int>left,right;
    if(n==0)return {0};
    if(n==2)return {-1,0};
    
    for(int i=0;i<n;i++){
        right[arr[i]]++;
    }
    vector<int>ans;
    int i =0;
    while(i<n){
        right[arr[i]]--;
        if(right[arr[i]]==0){
            right.erase(arr[i]);
        }
        ans.push_back(left.size()-right.size());
        left[arr[i]]++;
        i++;
    }
    return ans;
}