// https://leetcode.com/problems/find-median-from-data-stream/

#include<bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> dec;
    priority_queue<int, vector<int>, greater<int>> inc;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        dec.push(num);
        inc.push(dec.top());
        dec.pop();

        if (inc.size() > dec.size())
        {
            dec.push(inc.top());
            inc.pop();
        }
    }

    double findMedian()
    {
        if (inc.size() < dec.size())
            return dec.top();
        return 0.5 * (dec.top() + inc.top());
    }
};