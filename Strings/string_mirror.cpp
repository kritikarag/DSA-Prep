// https://practice.geeksforgeeks.org/problems/d385b9d635b7b10eef6bf365b84922aaeec9eb98/1

#include<bits/stdc++.h>
using namespace std;

string stringMirror(string str)
{
    // Code here
    string prefix = "";
    prefix += str[0];
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] > str[i - 1] || str[i] == str[0])
            break;
        prefix += str[i];
    }

    string temp = prefix;
    reverse(temp.begin(), temp.end());

    prefix += temp;

    return prefix;
}