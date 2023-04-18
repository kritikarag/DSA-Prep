// https://codeforces.com/problemset/problem/1350/B

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> costs(n);
        
        for (int i = 0; i < n; i++)
        {
            cin >> costs[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0][0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (costs[i] % costs[0] == 0)
                dp[0][i] = 2;
        }

        for (int i = 1; i < n; i++)
        {
            int temp = costs[i];
            dp[i][i] = max(dp[i - 1][i], 1);
            int val = dp[i][i];
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (costs[j] % temp == 0)
                    dp[i][j] = max(dp[i][j], val + 1);
            }
        }

        cout << dp[n - 1][n - 1] << endl;
    }

    return 0;
}