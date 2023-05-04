// https://practice.geeksforgeeks.org/problems/8d0e8785cef59cf4903b926ceb7100bcd16a9835/1

#include<bits/stdc++.h>
using namespace std;

bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_map<string,int> mp;
        
        for(auto i:arr)
        {
            string s=i;
            reverse(s.begin(),s.end());
            if(mp.find(s) != mp.end()) mp.erase(s);
            else mp[i]=1;
        }
        
        if(mp.size() == 0)return true;
        
        if(mp.size() == 1)
        {
            for(auto i:mp)
            {
                string s = i.first;
                string rs = i.first;
                reverse(rs.begin(),rs.end());
                if(s == rs)return true;
                else return false;
            }
        }
        
        return false;
    }