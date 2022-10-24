// https://leetcode.com/problems/longest-palindromic-subsequence/

#include<bits/stdc++.h>
using namespace std;

string lps(int n,int m, string &s1,){
    string s2 = s1;
    reverse(s2.begin(),s2.end());
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    int i=n;
    int j=m;

    string ans="";
    while(j>0&&i>0){
        if(s1[i-1]==s2[j-1]){
            ans = s1[i-1]+ans;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])i--;
        else j--;
    }

    return ans;

   // return dp[n][m]; -> will return the length of longest palindrome subsequence
}

int main()
{
    string s1 = "bbabcbcab";
    string s2 = s1;
    reverse(s2.begin(),s2.end()); 
    cout << "The Longest Common Subsequence is: " << lps(s1.size(), s2.size(), s1, s2) << endl;
    return 0;
}