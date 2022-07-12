vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>res;
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            if(st.size()==0)res.push_back(0);
            else if(st.size()>0 && st.top().first>temp[i]){
                res.push_back(st.top().second-i);
            }
            else{
                while(!st.empty() && temp[i]>=st.top().first){
                    st.pop();
                }
                if(st.empty())res.push_back(0);
                else res.push_back(st.top().second-i);
            }
            st.push({temp[i],i});
        }
        reverse(res.begin(),res.end());
        return res;
    }
