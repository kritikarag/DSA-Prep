// https://leetcode.com/problems/boats-to-save-people/description/

#include<bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    int ans = 0, n = people.size();
    sort(people.begin(), people.end());
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (people[i] + people[j] <= limit)
        {
            i++;
        }
        j--;
        ans++;
    }
    return ans;
}