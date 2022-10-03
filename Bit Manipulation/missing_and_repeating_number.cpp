// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include<bits/stdc++.h>
using namespace std;


int find_set_bit(int n){
    int count=1;
    while(n&1==0){
        count++;
        n>>1;
    }
    return count;
}

int *findTwoElement(int *arr, int n)
{
    // code here
    int sum =0, curr=0;
    for(int i=0;i<n;i++){
        sum^=(i+1);
        curr^=arr[i];
    }
    int req = curr^sum;
    int set_bit = find_set_bit(req);
    int check = 1<<set_bit; // check = req & ~(req-1)

    int *ans = new int(2);

    int xor1=0,xor2=0;

    for(int i=0;i<n;i++){
        if(arr[i]&check){
            xor1^=arr[i];
        }
        else{
            xor2^=arr[i];
        }
    }

    for(int i=1;i<=n;i++){
        if(i&check){
            xor1^=i;
        }
        else{
            xor2^=i;
        }
    }

    ans[0]=xor1, ans[1]=xor2;
    int x_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ans[0])
            x_count++;
    }

    if (x_count == 0)
        swap(ans[0], ans[1]);

    return ans;
}