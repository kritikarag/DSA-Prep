// https://practice.geeksforgeeks.org/problems/1e2f365be6114b671b915e145ec7dbcfdc432910/1

#include<bits/stdc++.h>
using namespace std;

string removeReverse(string str)
{
    string temp = str;
    unordered_map<char, int> mp;
    int i = 0, j = str.length() - 1;
    for (char c : str)
        mp[c]++;
    bool flag = true;
    int count = 0;
    string front = "", back = "";
    while (i <= j)
    {
        char c;
        if (flag)
            c = str[i++];
        else
            c = str[j--];

        if (mp[c] > 1)
        {
            mp[c]--;
            count++;
            flag = !flag;
        }
        else
        {
            if (flag)
                front += c;
            else
                back = c + back;
        }
    }

    string res = front + back;

    if (count % 2)
        reverse(res.begin(), res.end());

    return res;
    // code here
}