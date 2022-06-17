string longestCommonPrefix(vector<string>& strs) {
         int n=strs[0].length();
        string res="";
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i]){
                    flag=false;
                    break;
                }
            }
            if(flag)res+=strs[0][i];
            else break;
        }
        return res;
    }
