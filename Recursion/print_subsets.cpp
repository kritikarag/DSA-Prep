#include<bits/stdc++.h>
using namespace std;

// To store only the unique elements
unordered_set<string>s;
void printsubsets(string str, int i, string res){
    if(i>=str.length()){
        //cout << res << " ";
        s.insert(res);
        return;
    }

    printsubsets(str, i + 1, res + str[i]);
    printsubsets(str, i + 1, res);
} 

int main(){

    string str,res="";
    cin>>str;
    printsubsets(str,0,res);
    for(auto it:s){
        cout<<it<<endl;
    }
    return 0;
}