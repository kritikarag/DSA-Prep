#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>reqSum(vector<int>&nums, int target){
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int req = target - nums[i] - nums[j];
            int low = j+1, high = n-1;
            while(low<high){
                if(nums[low]+nums[high]<req)low++;
                else if(nums[low]+nums[high]>req)high--;
                else{
                    res.push_back({nums[i],nums[j],nums[low],nums[high]});

                    while(low<high && nums[low]==nums[low+1])++low;
                    while(low<high && nums[high]==nums[high-1])++high;
                }
            }
            while(j<n && nums[j]==nums[j+1])++j;
        }
        while(i<n && nums[i]==nums[i+1])++j;
    }

    return res;
}