#include<bits/stdc++.h>
using namespace std;

bool reversearray(int arr[],int n){
    
    if(n==1)return true;
    int i;
    for(i=1;i<n;i++){
        if(arr[i-1]>arr[i])break;
    }
    if(i==n)return true;

    int j=i;
    while(j<n && arr[j-1]>arr[j]){
        if(i>1 && arr[j]<arr[i-2])return false;
        j++;
    }

    if(j==n)return true;

    int k=j;
    while(k>1 && k<n){
        if(arr[k]<arr[k-1])return false;
        k++;
    }

    return true;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    reversearray(arr,n)?cout<<"YES": cout<<"NO";
    cout<<endl;
    return 0;
}