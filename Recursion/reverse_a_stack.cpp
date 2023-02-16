#include<bits/stdc++.h>
using namespace std;

void recurrent_reverse(stack<int>&st){

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