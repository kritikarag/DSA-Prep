int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
		int currsum=0,count=0;
		for(int i=0;i<nums.size();i++){
			currsum+=nums[i];
			int r=(currsum%k+k)%k;
			if(r==0)count++;
			if(mp.find(r)!=mp.end()) count+=mp[r];
			mp[r]++;
		}
		return count;
    }
