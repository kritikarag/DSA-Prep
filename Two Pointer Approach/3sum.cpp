#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for(int i=0;i<nums.size()-2;i++){
        if(i>0 && nums[i]==nums[i-1])i++;
        int low = i+1,high = nums.size()-1, target = 0;
        int curr = nums[low]+nums[high];
        if(curr<target)low++;
        else if(curr>target)high--;
        else{
            res.push_back({nums[i],nums[low],nums[high]});
            while(low<high && nums[low]==nums[low+1])low++;
            while(low<high && nums[high]==nums[high-1])high--;
            low++;
            high--;
        }
    }
}