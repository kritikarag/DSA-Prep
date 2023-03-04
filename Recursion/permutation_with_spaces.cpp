#include<bits/stdc++.h>
using namespace std;

set<string>s;
void permutation(string str, int i, string res){
    if(i==str.length()){
        s.insert(res);
        return;
    }

    permutation(str,i+1,res+"_"+str[i]);
    permutation(str,i+1,res+str[i]);
}
int main(){
    string str;
    cin>>str;
    string res="";
    res+=str[0];
    permutation(str,1,res);
    for(auto it:s){
        cout<<it<<endl;
    }
    return 0;
}