#include<bits/stdc++.h>
using namespace std;

void permutation(int open, int close, int n , string res){
    if(close==n){
        cout<<res<<endl;
        return;
    }
    if (open < n)
        permutation(open + 1, close, n, res + "(");
    if (close < open)
        permutation(open, close + 1, n, res + ")");
}

int main(){

    int n;
    cin>>n;
    int open = 0,close = 0;
    string res="";
    permutation(open,close,n,res);
    return 0;
}