#include<bits/stdc++.h>
using namespace std;

string lcs(int n, int m, string & a, string &b){
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]= 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    } 
    int i = n;
    int j = m;
    string str="";

    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            str= a[i-1]+str;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    // The above while loop can be replace with the following while loop:

    int curr=0;
    for(int i=1;i<=m;i++){
        if(dp[n][i]>curr){
            str = b[i-1]+str;
            curr++;
        }
    }
    return str;
}

int main(){
    string s1 = "abcde";
    string s2 = "bdgek";
    int n = s1.size(), m = s2.size();

    cout << "The Longest Common Subsequence is: " << lcs(n, m, s1, s2) << endl;
}