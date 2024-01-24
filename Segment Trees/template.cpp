// https://leetcode.com/problems/range-sum-query-mutable/description/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class SGTree{
    vector<int>seg;
    SGTree(int n){
        seg.resize(4*n);
    }
    void build(int index, int low, int high, vector<int>&arr){
        if(low==high){
            seg[index] = arr[low];
            return;
        }
        int mid = (high+low)/2;

        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);

        seg[index] = min(seg[2*index+1],seg[2*index+2]);
    }

    int query(int index, int low, int high, int l , int r){
        if(r < low || high < l)return INT_MAX;

        if(l<=low && r>=high){
            return seg[index];
        }

        int mid = (low+high)/2;
        int left = query(2*index+1,low,mid,l,r);
        int right = query(2*index+2,mid+1,high,l,r);

        return min(left,right);
    }

    void update(int index, int low, int high, int i, int val){
        if(i < low || i > high)return ;
        if(low==high){
            seg[index] = val;
            return;
        }

        int mid = (low+high)/2;
        if(i<=mid){
            update(2*index+1,low,mid,i,val);
        }
        else{
            update(2*index+2,mid+1,high,i,val);
        }
        seg[index] = min(seg[2*index+1],seg[2*index+2]);
    }
    // make an update in the main function to the original array too
};