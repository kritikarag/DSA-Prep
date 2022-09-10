#include<bits/stdc++.h>
using namespace std;

int countpaths(int arr[],int n, int m,int cost,int k){
    if(n==0||m==0){
        if(cost%k==0)return 1;
        else return 0;
    }

    if(n==0)countpaths(arr,n,m-1,cost+arr[n][m],k);
    if(m==0)countpaths(arr,n-1,m,cost+arr[n][m],k);

    return countpaths(arr, n, m - 1, cost + arr[n][m], k) + countpaths(arr, n - 1, m, cost + arr[n][m], k);
}

int count_paths(int arr[],int n,int m,int cost,int k){
    
}