// https://leetcode.com/problems/patching-array/

int minPatches(vector<int>& nums, int n) {
    long long len = nums.size(), curr = 0, track = 1, ans = 0;

    for(int i=0;i<len;i++){
        while(nums[i]> track){
            cout<<track<<" ";
            curr+=track;
            track = curr+1;
            ans++;
            if(track>n)break;
        }

        curr+=nums[i];
        track = curr+1;
        if(track>n)break;
    }

    while(track<=n){
        ans++;
        curr+=track;
        track = curr+1;
    }
    return ans;
}
