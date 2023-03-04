#include<bits/stdc++.h>
using namespace std;

unordered_set<string>s;
void permutation(string str, int i, string res){
    if(i==str.length()){
        s.insert(res);
        return;
    }

    permutation(str, i + 1, res + str[i]);
    char temp = str[i]-32;
    permutation(str, i + 1, res + temp);
}
int main(){
    string str;
    cin>>str;
    string res="";
    permutation(str, 1, res + str[0]);
    char temp = str[0]-32;
    permutation(str, 1, res + temp);

    for(auto it: s){
        cout<<it<<endl;
    }
    return 0;
}