void getpar(vector<string>&ans,int open,int close, string curr){
        if(!close){
            ans.push_back(curr);
            return;
        }
        if(open>0)getpar(ans,open-1,close,curr+"(");
        if(close>open)getpar(ans,open,close-1,curr+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        getpar(ans,n,n,"");
        return ans;
    }
