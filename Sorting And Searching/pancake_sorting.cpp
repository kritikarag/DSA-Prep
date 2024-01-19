// https://leetcode.com/problems/pancake-sorting/

#include<bits/stdc++.h>
using namespace std;

vector<int> pancakeSort(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    int target = n - 1;

    while (target > 0)
    {
        int maxi = 0;
        for (int i = 0; i <= target; i++)
        {
            if (arr[i] > arr[maxi])
            {
                maxi = i;
            }
        }
        cout << target << endl;
        if (maxi == target)
        {
            target--;
            continue;
        }
        if (maxi == 0)
        {
            ans.push_back(target + 1);
            reverse(arr.begin(), arr.begin() + target + 1);
            target--;
        }
        else
        {
            ans.push_back(maxi + 1);
            reverse(arr.begin(), arr.begin() + maxi + 1);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>vec(n);

    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int>ans = pancakeSort(vec);
    for(int i:ans){
        cout<<i<<" ";
    }
    
    return 0;
}