int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
           pq.push(nums[i]);
        }
         
        int i=1;
        while(i<k){
            pq.pop();
            i++;
        }
        return pq.top();
    }
