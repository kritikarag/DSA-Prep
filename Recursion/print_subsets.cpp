#include<bits/stdc++.h>
using namespace std;

void printsubsets(string str, int i, string res){
    if(i>=str.length()){
        cout << res << " ";
        return;
    }

    printsubsets(str, i + 1, res + str[i]);
    printsubsets(str, i + 1, res);
} 

int main(){

    string str,res="";
    cin>>str;
    printsubsets(str,0,res);
    return 0;
}