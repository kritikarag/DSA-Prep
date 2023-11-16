//
#include<bits/stdc++.h>
using namespace std;
// Method 1

class Solution
{
public:
    long long convert(long long n)
    {
        long long dec = 0, i = 0, rem;

        while (n != 0)
        {
            rem = n % 10;
            n /= 10;
            dec += rem * pow(2, i);
            ++i;
        }

        return dec;
    }
    string to_binary(long long n)
    {
        string ans = "";
        while (n)
        {
            if (n & 1)
            {
                ans = "1" + ans;
            }
            else
            {
                ans = "0" + ans;
            }
            n >>= 1;
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<long long> s;

        long long n = nums.size();
        long long len = n;
        n = pow(2, n);

        for (long long i = 0; i < n; i++)
        {
            s.insert(i);
        }

        for (long long i = 0; i < nums.size(); i++)
        {
            long long curr = convert(stoll(nums[i]));
            s.erase(curr);
        }
        string result = to_binary(*s.begin());
        // cout<<len<<endl;
        while (result.length() < len)
        {
            result = "0" + result;
        }
        return result;
    }
};

// Method 2

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string ans = "";
        for (int i = 0; i < nums.size(); i++)
        {
            ans += nums[i][i] == '0' ? "1" : "0";
        }

        return ans;
    }
};