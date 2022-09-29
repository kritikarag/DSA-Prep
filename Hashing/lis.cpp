//Find the length of longest increarsing subsequence

int list(vector<int>&nums){
    unordered_set<int>st;
    for(int i:nums){
        st.insert(i);
    }

    int res=0;
    int curr_num, len;
    for(int num: nums){
        if(st.find(nums-1)==st.end()){
            len=1;
            curr_num = num;

            while (st.find(num + 1) != st.end())
            {
                curr_num++;
                len++;
            }

            res = max(res, len);
        }
    }

    return res;
}