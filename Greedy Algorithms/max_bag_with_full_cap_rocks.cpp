// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

int maximumBags(vector<int> &cap, vector<int> &rocks, int k)
{
    vector<int> count;
    for (int i = 0; i < rocks.size(); i++)
        cap[i] -= rocks[i];
    sort(cap.begin(), cap.end());
    int ans = 0;
    for (int it : cap)
    {
        if (it > k)
            break;
        else
        {
            ans++;
            k = k - it;
        }
    }
    return ans;
}