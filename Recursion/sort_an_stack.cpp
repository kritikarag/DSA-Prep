#include<bits/stdc++.h>
using namespace std;

// Descending Order
void descendinginsertion(stack<int>&st, int x){
    if(st.size()==0||st.top()<=x){
        st.push(x);
        return;
    }
    int val = st.top();
    st.pop();
    descendinginsertion(st,x);
    st.push(val);
    return;
}

void descendingsortstack(stack<int> &st)
{
    if (st.size() <= 1)
        return;
    int temp = st.top();
    st.pop();
    descendingsortstack(st);
    descendinginsertion(st, temp);
}

// Ascending Order 
void ascendinginsertion(stack<int> &st, int x)
{
    if (st.size() == 0 || st.top() >= x)
    {
        st.push(x);
        return;
    }
    int val = st.top();
    st.pop();
    ascendinginsertion(st, x);
    st.push(val);
    return;
}

void ascendingsortstack(stack<int>&st){
    if(st.size()<=1)return;
    int temp = st.top();
    st.pop();
    ascendingsortstack(st);
    ascendinginsertion(st,temp);
}


int main(){ 
    stack<int>st1,st2;

    st1.push(42);
    st1.push(16);
    st1.push(76);
    st1.push(53);
    st1.push(34);

    int n = st1.size();
    ascendingsortstack(st1);

    cout<<"Ascending Sort: ";
    for(int i=0;i<n;i++){
        cout<<st1.top()<<" ";
        st1.pop();
    }

    cout<<endl;

    st2.push(42);
    st2.push(16);
    st2.push(76);
    st2.push(53);
    st2.push(34);

    int m = st2.size();
    descendingsortstack(st2);

    cout << "Descending Sort: ";
    for (int i = 0; i < m; i++)
    {
        cout << st2.top() << " ";
        st2.pop();
    }

    return 0;
}