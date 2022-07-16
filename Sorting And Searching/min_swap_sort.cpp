#include<bits/stdc++.h>
using namespace std;
void swap(vector<int>&vec,int i,int j){
        int temp = vec[i];
        vec[i]=vec[j];
        vec[j]=temp;
    }
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int ans=0;
	    map<int,int>mp;
	    vector<int>temp=nums;
	    sort(temp.begin(),temp.end());
	    int n=nums.size();
	    for(int i=0;i<n;i++){
	        mp[nums[i]]=i;
	    }
	    
	    for(int i=0;i<n;i++){
	        if(nums[i]!=temp[i]){
	            ans++;
	            int init = nums[i];
	            
	            swap(nums,i,mp[temp[i]]);
	            
	            mp[init]=mp[temp[i]];
	            mp[temp[i]]=i;
	        }
	    }
	    
	    return ans;
	}
