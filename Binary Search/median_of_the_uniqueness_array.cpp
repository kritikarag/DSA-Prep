// https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/description/

using ll = long long;
ll atMostK(vector<int>&nums, int k){
    int n = nums.size();
    unordered_map<ll,ll>mp;
    ll left = 0, count = 0;

    for(int i=0;i<n;i++){
        mp[nums[i]]++;
        if(mp.size()>k){
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
        }
        count += (i-left+1);
    }
    return count;
}
int medianOfUniquenessArray(vector<int>& nums) {
    ll n = nums.size();
    ll total = ((n+1)*n)/2;
    ll median = (total+1)/2, ans = 1;
    ll left =1, right = n;

    while(left<right){
        ll mid = (right-left)/2+left;
        ll count = atMostK(nums,mid); 
        if(count>=median){
            ans = mid;
            right = mid;
        }
        else{
            left = mid+1;
        }
    }

    return ans;
}
