#include<bits/stdc++.h>
using namespace std;

vector<char>duplicates(string s,vector<char>&vec){
    //vector<char>vec;
    unordered_map<char,int>mp;
    for(int i;i<s.length();i++){
        mp[s[i]]++;
    }
    for(auto i:mp){
        if(i.second>1)vec.push_back(i.first);
    }
    return vec;
}

int main(){
    string s;
    getline(cin>>ws,s);
    vector<char>vec;
    duplicates(s,vec);
    for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";
    cout<<endl;
}