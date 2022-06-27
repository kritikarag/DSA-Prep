int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int prefix[nums.size()];
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
             prefix[i]=nums[i]+prefix[i-1];
        }
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(k==prefix[i])count++;
            if(mp.find(prefix[i]-k)!=mp.end())count+=mp[prefix[i]-k];
            mp[prefix[i]]++;
        }
        return count;
    }
