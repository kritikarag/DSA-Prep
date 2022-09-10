#include<bits/stdc++.h>
using namespace std;

int longestsubarray(int arr[],int n,int k){
    vector<int>pref(n);
    pref[0]=arr[0];
    for(int i=0;i<n;i++){
        pref[i]=pref[i-1]+arr[i];
    }

    int ans=0;
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        if(pref[i]==k){
            ans=max(ans,i+1);
        }

        int req = pref[i]-k;
        if(mp.find(req)!=mp.end()){
            ans = max(ans,i-mp[req]);
        }

        if(mp.find(req)==mp.end()){
            mp[pref[i]]=i;
        }
    }

    return ans;
}