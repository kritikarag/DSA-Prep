string simplifyPath(string path) {
        string result="";
        stack<string>st;
        int n = path.length();
        for(int i=0;i<n;i++){
            if(path[i]=='/')continue;
            
            string temp="";
            while(i<n && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            
            if(temp==".")continue;
            else if(temp==".."){
                if(!st.empty())st.pop();
                else continue;
            }
            else st.push(temp);
        }
        
        while(!st.empty()){
            result = '/'+st.top()+result;
            st.pop();
        }
        if(result.size()==0)return"/";
        return result;
    }
