int evaluatePostfix(string s)
    {
        stack<int>st;
        int a,b;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i]))st.push(s[i]-'0');
            
            switch(s[i]){
                case '/': 
                a=st.top();st.pop();
                b=st.top();st.pop();
                st.push(b/a);
                break;
                
                case '*': 
                a=st.top();st.pop();
                b=st.top();st.pop();
                st.push(b*a);
                break;
                
                case '+': 
                a=st.top();st.pop();
                b=st.top();st.pop();
                st.push(b+a);
                break;
                
                case '-': 
                a=st.top();st.pop();
                b=st.top();st.pop();
                st.push(b-a);
                break;
            }
        }
        
            return st.top();
    }
