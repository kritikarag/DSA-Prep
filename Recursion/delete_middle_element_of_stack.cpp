#include<bits/stdc++.h>
using namespace std;

void deletemiddle(stack<int>&st, int count){
    if(count>=st.size()-1){
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    deletemiddle(st,count+1);
    st.push(temp);
    return;
}

int main()
{
    stack<int> st;

    st.push(42);
    st.push(16);
    st.push(76);
    st.push(53);
    st.push(34);
    st.push(32);

    int n = st.size();
    deletemiddle(st,0);

    for(int i=0;i<n-1;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}