// https://practice.geeksforgeeks.org/problems/6bb49b563cc171335c6564b00307a6d867e0268d/1

#include<bits/stdc++.h>
using namespace std;
bool is_possible_to_get_seats(int n, int m, vector<int> &seats)
{
    // Write your code here.
    for (int i = 0; i < m; i++)
    {
        if (i == 0 && seats[i] == 0)
        {
            if (seats[1] == 0)
            {
                seats[0] = 1;
                n--;
            }
        }
        else if (i == m - 1 && seats[i] == 0)
        {
            if (seats[m - 2] == 0)
            {
                seats[m - 1] = 1;
                n--;
            }
        }
        else
        {
            if (seats[i - 1] == 0 && seats[i + 1] == 0 && seats[i] == 0)
            {
                seats[i] = 1;
                n--;
            }
        }
    }
    
    return (n <= 0);
}