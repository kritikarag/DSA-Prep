#include<bits/stdc++.h>
using namespace std;

void permutation(string str, int i, string res){
    if(i==str.length()){
        cout<<res<<endl;
        return;
    }

    if (str[i] >= 'A' && str[i] <= 'Z'){
        char temp = str[i]+32;
        permutation(str,i+1,res+temp);
    }
    else if(str[i] >= 'a' && str[i] <= 'z'){ 
        char temp = str[i] - 32;
        permutation(str, i + 1, res + temp);
    }
    permutation(str, i + 1, res + str[i]);
}

int main(){
    string str;
    cin>>str;
    string res="";
    permutation(str,0,res);
    return 0;
}