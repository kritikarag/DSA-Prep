// https://practice.geeksforgeeks.org/problems/61567fb59e9f202db5cc2ad320ffeb6d95bf72d7/1

#include<bits/stdc++.h>
using namespace std;
bool wifiRange(int N, string S, int X)
{
    // code here
    int cnt = 0;
    for (const auto &x : S)
    {
        if (x == '0')
            cnt--;
        else if (x == '1')
            cnt = X;

        if (cnt < -X)
            return false;
    }

    return cnt >= 0;
}