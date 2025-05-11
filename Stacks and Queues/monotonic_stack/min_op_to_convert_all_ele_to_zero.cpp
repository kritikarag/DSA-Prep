// https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/
int minOperations(vector<int>& nums) {
        int n = nums.size(), ans=0;

        stack<int>st;
        for(int num:nums){
            while(!st.empty() && st.top()>num){
                ans++;
                st.pop();
            }

            if(!st.empty() && st.top()==num)continue;
            if(num!=0)st.push(num);
        }
        ans+=st.size();
        return ans;
    }
