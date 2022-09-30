#include<bits/stdc++.h>
using namespace std;

int maxLength(vector<int>&nums){
    int len=0,curr=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            curr++;
            len=max(len,curr);
        }
        else{
            curr=0;
        }
    }
    return len;
}

int main(){
    vector<int>nums = {0,1,1,1,00,1,1,1,1,1,0,1,1,0,0,1,1,1,1};
    cout<<maxLength(nums)<<endl;
    return 0;
}