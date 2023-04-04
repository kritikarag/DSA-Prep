// https://practice.geeksforgeeks.org/problems/6a1b365b520f10c8a29b533eb72951b4b4237b57/1

#include<bits/stdc++.h>
using namespace std;

int minSteps(string str)
{ 

    int counta = 0, countb = 0;
    int i = 0, n = str.length();
    while (i < n)
    {
        if (str[i] == 'a')
        {
            while (str[i++] == 'a')
                continue;
            counta++;
        }
        else
        {
            while (str[i++] == 'b')
                continue;
            countb++;
        }
        i--;
    }

    int res = min(counta, countb) + 1;
    return res;
}