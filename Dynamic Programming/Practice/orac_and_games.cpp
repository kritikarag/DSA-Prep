// https://codeforces.com/problemset/problem/1350/B

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> costs(n+1);
        
        for (int i = 1; i <= n; i++)
        {
            cin >> costs[i];
        }

        vector<int> dp(n+1, 1);  

        for (int i = 1; i <= n; i++)
        {
            for (int j = 2*i; j <= n; j+=i)
            {
                if(costs[j]>costs[i])dp[j] = max(dp[j],dp[i]+1);
            }
        }

        cout <<*max_element(dp.begin(),dp.end()) << endl;
    }

    return 0;
}