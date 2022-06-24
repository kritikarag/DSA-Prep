vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>st;
        map<int,int>mp;
        int n=nums2.size();
        int m=nums1.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i])st.pop();
            if(st.empty())mp[nums2[i]]=-1;
            else mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        
        for(int i=0;i<m;i++){
            ans.push_back(mp[nums1[i]]);
        }
        
        return ans;
    }
