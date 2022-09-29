#include<bits/stdc++.h>
using namespace std;

int lengthofLS(vector<int>&nums){
    unordered_map<int,int>mp;
    int sum = 0, len=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==0){
            len = max(len,i+1);
        }
        else {
            if(mp.find(num)!=mp.end()){
                len = max(len, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
    }

    return len;
}