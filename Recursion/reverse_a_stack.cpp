#include<bits/stdc++.h>
using namespace std;

void insert_at_the_bottom(stack<int>&st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insert_at_the_bottom(st,x);

    st.push(temp);
    
}

void recurrent_reverse(stack<int>&st){
    if(st.size()<1)return;
    int temp = st.top();
    st.pop();
    recurrent_reverse(st);

    insert_at_the_bottom(st,temp);

}

int main(){
    int n;
    cin>>n;
    stack<int>st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.push(x);
    }

    recurrent_reverse(st);

    for(int i=0;i<n;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}