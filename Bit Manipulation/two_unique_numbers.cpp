// Given an array in which every number appears twice except for the two of them
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    int sum=0;

    for(int i=0;i<n;i++){
        cin>>vec[i];
        sum^=vec[i];
    }
    int count =0;
    while(sum){
        if(sum&1)break;
        count++;
        sum=sum>>1;
    }

    int xor1=0,xor2=0;
    for(int i=0;i<n;i++){
        if(vec[i]&1<<count){
            xor1 = xor1^vec[i];
        }
        else xor2 = xor2^vec[i];
    }

    cout<<xor1<<" "<<xor2;
    return 0;
}