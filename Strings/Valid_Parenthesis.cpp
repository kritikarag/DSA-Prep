bool isValid(string s) {
        stack<char>st;
        char x;
        int n= s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
                continue;
            }
            
            else if(st.empty())return false;
            
            switch(s[i]){
        case ')':
            
            
            x = st.top();
            st.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            
            x = st.top();
            st.pop();
            if (x == '(' || x == '[')
                return false;
            break;
        
        case ']':

            
            x = st.top();
            st.pop();
            if (x == '(' || x == '{')
                return false;
            break;
            }
        }
        return (st.empty());
    }
