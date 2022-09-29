#include<bits/stdc++.h>
using namespace std;

// int length(vector<int>&nums){
//     int len =0;
//     int l=0,r=0;
//     set<int>s;
//     while(l<nums.size()&&r<nums.size()){
//         while(s.find(nums[r])!=s.end()){
//             s.erase(nums[l++]);
//         }
//         len = max(len,l-r+1);
//         s.insert(nums[r++]);
//     }

//     return len;
// }

// Time Optimized

int longestSS(string &nums)
{
    int len = 0;
    int l = 0, r = 0;
    vector<char>mp(256,-1);
    while (r < nums.length())
    {
        if(mp[nums[r]]!=-1){
            l = max(mp[nums[r]]+1,l);
        }
        mp[nums[r]]=r;
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}

int main(){
    string words = "abcaabcdda";
    cout<<longestSS(words)<<endl;
    return 0;
}