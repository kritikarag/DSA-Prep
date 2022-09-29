#include<bits/stdc++.h>
using namespace std;

int count(vector<int>&nums, int target){
    int res=0;

    int xor_sum=0;
    uordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        xor_sum^=nums[i];
        if(sum==target){
            res++;
        }
        else{
            if(mp.find(xor_sum^target)!=mp.end()){
                res+=mp[xor_sum^target];
            }
            mp[xor_sum]++;
        }
    }

    return res;
}