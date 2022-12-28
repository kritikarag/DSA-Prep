// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> pq;
    for (int it : piles)
        pq.push(it);
    while (k-- && pq.top() > 1)
    {
        int curr = pq.top();
        pq.pop();
        curr -= curr / 2;
        pq.push(ceil(curr));
    }
    int ans = 0;
    while (!pq.empty())
    {
        // cout<<pq.top()<<" ";
        ans += pq.top();
        pq.pop();
    }
    return ans;
}