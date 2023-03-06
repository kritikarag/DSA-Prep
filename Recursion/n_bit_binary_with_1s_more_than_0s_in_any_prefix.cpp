#include<bits/stdc++.h>
using namespace std;

void permutation(int zero, int one,int n, string res){
    if(n==0){
        cout<<res<<endl;
        return;
    }
    if(zero<one){
        permutation(zero+1,one,n-1,res+"0");
    }
    permutation(zero,one+1,n-1,res+"1");
}
int main(){
    int n;
    cin>>n;
    string res="";
    int zero=0,one=0;
    permutation(zero,one,n,res);
    return 0;
}