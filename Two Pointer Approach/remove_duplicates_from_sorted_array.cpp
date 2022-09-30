#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(vector<int> &nums)
{
    int i = 0, j = 1;
    while (j < nums.size())
    {
        if (nums[i] == nums[j])
        {
            while (j < nums.size() && nums[i] == nums[j])
                j++;
        }
        nums[++i] = nums[j++];
    }
}

void removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for(int j=1;j<nums.size();j++){
        if(nums[i]!=nums[j]){
            nums[++i]=nums[j];
        }
    }
}

int main(){
    vector<int>nums = {1,2,2,2,3,3,4,5,5,6,7,7,7,8};
    removeDuplicates(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}